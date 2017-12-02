#ifndef IntRes
#define IntRes
#include"Resource.h"
class IntResource:public Resource
{
    int* value;

    public:
        IntResource()
        {
            value = 0;
        }

        void reset()
        {
            value = 0;
        }

        void* getValue()
        {
            return value;
        }

        void setValue(const void* number)
        {
            value = (int*)number;
        }
        
        ~IntResource()
        {
        	delete value;
        }
};

#endif
