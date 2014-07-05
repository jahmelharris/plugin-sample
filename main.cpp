#include <iostream>
#include "pluginManager.h"
using namespace std;

int main()
{
	PluginManager pluginManager;
	pluginManager.loadAllPlugins();
	
	pluginManager.destroyAllPlugins();
	return 0;
}
