#include"ObjectPool.h"
#include"Resource.h"
#include"IntResource.h"
#include"StringResource.h"
#include"PriorityTracker.h"
#include<cstring>

ObjectPool* ObjectPool::instance = 0;

using namespace std;
int main()
{
    
    ObjectPool* pool = ObjectPool::getInstance();
    std::cout << "pool created " << " [" << pool << "]" << std::endl;
    Resource* one;
    Resource* two;
    Resource* three;
    Resource* four;
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
    
    three = (Resource*)pool->getResource("IntResource");
    int num2=64;
    three->setValue(&num2);
    std::cout << "three = " << *(int*)(three->getValue())<< " [" << three << "]" << std::endl;

    four = (Resource*)pool->getResource("StringResource");
    const char* str2="chiku";
    four->setValue(str2);
    std::cout << "four = " << (char*)(four->getValue()) << " [" << four << "]" << std::endl;
    Destroyer::SetLongevity((IntResource*)one,1,0);
    Destroyer::SetLongevity((StringResource*)two,2,0);
    Destroyer::SetLongevity((IntResource*)three,1,1);
    Destroyer::SetLongevity((StringResource*)four,2,1);
    
    pool->returnResource("IntResource",one);
    pool->returnResource("StringResource",two);

    /* Resources will be reused. 
     */
    one = pool->getResource("IntResource");
    one->setValue(&num);
    std::cout << "one = " << *(int*)(one->getValue()) << " [" << one << "]" << std::endl;

    two = pool->getResource("StringResource");
    const char* str3="hi";
    two->setValue(str3);
    std::cout << "two = " << (char*)(two->getValue()) << " [" << two << "]" << std::endl;
    Destroyer::AtExitFn();
    delete pool;	
    return 0;
}
