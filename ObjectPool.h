#include <string>
#include <iostream>
#include <list>
#include <map>
#include <iterator>
#include"Factory.h"
#include"Resource.h"
#ifndef ObjPl
#define ObjPl
/* Note, that this class is a singleton. */
class ObjectPool
{
    private:
        std::map<std::string,std::list<void*> > resources;
        
        static ObjectPool* instance;
        
        ObjectPool() {}

    public:
    	 factory* g_factory=new factory();
        /**
         * Static method for accessing class instance.
         * Part of Singleton design pattern.
         *
         * @return ObjectPool instance.
         */
        static ObjectPool* getInstance()
        {
	    if (instance == 0)
	    {
		instance = new ObjectPool;
	    }
	    return instance;
	}

        /**
         * Returns instance of specified parameter.
         * 
         * New resource will be created if all the resources
         * were used at the time of the request.
         *
         * @param str Class name
         * @return Resource instance.
         */
        Resource* getResource(std::string str);
        
        
        /**
         * Return resource back to the pool.
         *
         * The resource must be initialized back to
         * the default settings before someone else
         * attempts to use it.
         *
         * @param str Key for class name
         * @param object Resource instance.
         * @return void
         */
        void returnResource(std::string str,void* object);
        
        /**
         * The Destructor to avoid memory leak
         */
        ~ObjectPool();
};

#endif
