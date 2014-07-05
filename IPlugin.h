#ifndef IPLUGIN_H
#define IPLUGIN_H

class IPlugin
{
	public:
	virtual void func1() = 0;
	virtual void initPlugin() = 0;
	virtual void destroyPlugin() = 0;
};


#endif
