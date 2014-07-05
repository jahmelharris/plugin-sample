#include <iostream>                                     
//#include "IPlugin.h"                                  
//class Plugin1 : IPlugin{                              
//      void func1(){std::cout<<"in function 1\n";}     
//};                                                    
class Plugin1 : public IPlugin                        
{                                                       
        public:                                         
        void func1();//{std::cout<<"in function 1\n";}     
        void initPlugin();//{std::cout<<"init plugin\n";}  
	//~Plugin1();
	void destroyPlugin();
	void getPlugin(void){std::cout<<"getPlugin called\n";}
};                                                      
