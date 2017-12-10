#ifndef IntRes
#define IntRes
#include"Resource.h"
using namespace std;
class IntResource:public Resource
{
    int* value;

    public:
        IntResource()
        {
            value = NULL;
        }

        void reset()
        {
            value = NULL;
        }

        void* getValue()
        {
            return value;
        }

        void setValue(const void* number)
        {
            value = new int;
            *value=*((int*)number);
        }
        
        ~IntResource()
        {
        	std::cout<<"deleting [" <<this<<"]"<<std::endl;
        	if(this->value)
        	delete this->value;
        }
};

#endif
