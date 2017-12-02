#include"ObjectPool.h"



using namespace std;
/**
 * Returns instance of specified parameter.
 * 
 * New resource will be created if all the resources
 * were used at the time of the request.
 *
 * @param str Class name
 * @return Resource instance.
 */
Resource* ObjectPool::getResource(string str)
{
    map<std::string,std::list<void*> >::iterator itr=resources.find(str);
    if (itr==resources.end())
    {
        std::cout << "Creating new." << std::endl;
        return (Resource*)(instance->g_factory->construct(str));
    }
    else
    {
        std::cout << "Reusing existing." << std::endl;
        
        Resource* resource = (Resource*)itr->second.front();
        itr->second.pop_front();
        return resource;
    }
}

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
void ObjectPool::returnResource(string str,void* object)
{
    map<std::string,std::list<void*> >::iterator itr=resources.find(str);
    if(itr==resources.end())
    {
    	list<void*> l;
    	resources.insert(pair<std::string,std::list<void*> >(str,l));
    	resources.find(str)->second.push_back(object);
    }
    else
    {
    	resources.find(str)->second.push_back(object);
    }
}

/**
 * The Destructor to avoid memory leak
 */
ObjectPool::~ObjectPool()
{
	resources.clear();
}
