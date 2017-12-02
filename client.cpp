#include"ObjectPool.h"
#include"Resource.h"
#include"IntResource.h"
#include"StringResource.h"
#include<cstring>

ObjectPool* ObjectPool::instance = 0;

using namespace std;
int main()
{
    ObjectPool* pool = ObjectPool::getInstance();
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

    pool->returnResource("IntResource",one);
    pool->returnResource("StringResource",two);

    /* Resources will be reused. 
     */
    one = pool->getResource("IntResource");
    std::cout << "one = " << *(int*)(one->getValue()) << " [" << one << "]" << std::endl;

    two = pool->getResource("StringResource");
    const char* str2="hi";
    two->setValue(str2);
    std::cout << "two = " << (char*)(two->getValue()) << " [" << two << "]" << std::endl;
   
    return 0;
}
