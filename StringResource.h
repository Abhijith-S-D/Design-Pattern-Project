#ifndef StrRes
#define StrRes
#include <cstring>
#include<iostream>
#include"Resource.h"
using namespace std;
class StringResource:public Resource
{
    char* value;

    public:
        StringResource()
        {
            value = NULL;
        }

        void reset()
        {
            delete[] value;
            value=NULL;
        }

        void* getValue()
        {
            return value;
        }

        void setValue(const void* a)
        {
            delete[] value;
            value=NULL;
            string st((const char*)a);
            value = new char[st.length() + 1];
            strcpy(value, st.c_str());
            
        }
        
        ~StringResource()
        {
        	std::cout<<"deleting [" <<this<<"]"<<std::endl;
        	if(this->value)
        	delete[] this->value;
        }
};

#endif
