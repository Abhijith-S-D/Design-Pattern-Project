#include"ObjectPool.h"
#include"Resource.h"

ObjectPool* ObjectPool::instance = 0;

using namespace std;
int main()
{
    ObjectPool* pool = ObjectPool::getInstance();
    Resource* one;
    std::string* two;
    pool->g_factory->register_class<string>("string");
    pool->g_factory->register_class<Resource>("Resource");
    /* Resources will be created. */
    one = (Resource*)pool->getResource("Resource");
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = (std::string*)pool->getResource("string");
    *two = "foobar";
    std::cout << "two = " << *two << " [" << two << "]" << std::endl;

    pool->returnResource("Resource",one);
    pool->returnResource("string",two);

    /* Resources will be reused. 
     */
    one = (Resource*)pool->getResource("Resource");
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = (std::string*)pool->getResource("string");
    std::cout << "two = " << *two << " [" << two << "]" << std::endl;
   
    return 0;
}
