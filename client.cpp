#include"ObjectPool.h"
#include"Resource.h"
#include"IntResource.h"
#include"StringResource.h"
#include"LifetimeTracker.h"
#include<cstring>

ObjectPool* ObjectPool::instance = 0;

using namespace std;
int main()
{
    
    ObjectPool* pool = ObjectPool::getInstance();
    std::cout << "pool created " << " [" << pool << "]" << std::endl;
    Resource* one;
    Resource* two;
    pool->g_factory->register_class<IntResource>("IntResource");
    pool->g_factory->register_class<StringResource>("StringResource");
    /* Resources will be created. */
    one = (Resource*)pool->getResource("IntResource");
    int num=10;
    one->setValue(&num);
    std::cout << "one = " << *(int*)(one->getValue())<< " [" << one << "]" << std::endl;

    two = (Resource*)pool->getResource("StringResource");
    const char* str="hello";
    two->setValue(str);
    std::cout << "two = " << (char*)(two->getValue()) << " [" << two << "]" << std::endl;
    Destroyer::SetLongevity((IntResource*)one,1);
    Destroyer::SetLongevity((StringResource*)two,2);
    
    pool->returnResource("IntResource",one);
    pool->returnResource("StringResource",two);

    /* Resources will be reused. 
     */
    one = pool->getResource("IntResource");
    one->setValue(&num);
    std::cout << "one = " << *(int*)(one->getValue()) << " [" << one << "]" << std::endl;

    two = pool->getResource("StringResource");
    const char* str2="hi";
    two->setValue(str2);
    std::cout << "two = " << (char*)(two->getValue()) << " [" << two << "]" << std::endl;
    Destroyer::AtExitFn();
    delete pool;	
    return 0;
}
