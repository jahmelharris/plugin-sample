#ifndef _PLUGIN_MANAGER_H
#define _PLUGIN_MANAGER_H
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>

#include <vector>
#include "IPlugin.h"

class PluginManager
{
	private:
		std::vector<IPlugin*> plugins;
		std::vector<void*> handleList;
		void loadFromDisk()
		{
			std::vector<std::string>* filenames = getFilenames();

			for(std::vector<std::string>::iterator it = filenames->begin(); it != filenames->end(); ++it)
			{
				std::cout<<*it<<std::endl;	
				std::string file = *it;
				
				void* handle = dlopen(std::string("plugins/"+file).c_str(), RTLD_LAZY);
				if(!handle)
				{
					std::cout<<"error opening library\n";
				}
				void* ptr = dlsym(handle, "getPlugin");
				IPlugin* plugin = ((IPlugin* (*)())ptr)();
				plugins.push_back(plugin);
				handleList.push_back(handle);
			}
			delete filenames;
		}

		std::vector<std::string>* getFilenames()
		{
			std::vector<std::string>* filenames = new std::vector<std::string>();
	
			DIR *dp;
			struct dirent *dirp;
			if((dp  = opendir("plugins/")) == NULL) 
			{
				std::cout << "Error opening " << "plugins/" << std::endl;
			}
			while ((dirp = readdir(dp)) != NULL) 
			{
				std::string filename = dirp->d_name;
				if(filename != "." &&  filename != "..")
				{
					filenames->push_back(std::string(dirp->d_name));
				}
			}
			closedir(dp);
			return filenames;
	
		}

		void initAllPlugins()
		{
			for(std::vector<IPlugin*>::iterator it = plugins.begin(); it != plugins.end(); ++it)
			{
				IPlugin* p = (IPlugin*)*it;
				p->initPlugin();
			}
		}
	public:
	PluginManager(){};
	void loadAllPlugins()
	{
		loadFromDisk();
		initAllPlugins();
	}
	void destroyAllPlugins()
	{
		for(std::vector<IPlugin*>::iterator it = plugins.begin(); it != plugins.end(); ++it)
		{
			std::cout<<"deleting plugins\n";
			((IPlugin*)*it)->destroyPlugin();
			delete *it;
		}
		for(std::vector<void*>::iterator it = handleList.begin(); it != handleList.end(); ++it)
		{
			dlclose(*it);
		}

	}
	
};
#endif
