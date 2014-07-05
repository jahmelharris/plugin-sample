#include <iostream>
#include "IPlugin.h"
#include "plugin1.h"
void Plugin1::func1()
{
	std::cout<<"in function 1\n";
}       
void Plugin1::initPlugin()
{
	std::cout<<"init plugin\n";
}    
//Plugin1::~Plugin1()
void Plugin1::destroyPlugin()
{
	std::cout<<"Plugin destroyed\n";
}

extern "C" {
	IPlugin* getPlugin(void)
	{
		std::cout<<"get plugin\n";
		IPlugin* plugin = new Plugin1();
		return plugin;
	}
	
}
