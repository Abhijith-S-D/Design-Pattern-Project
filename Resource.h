#ifndef Res
#define Res
class Resource
{

    public:
        Resource()
        {
        }

        virtual void reset()
        {
        }

        virtual void* getValue()
        {
        }

        virtual void setValue(const void*)
        {
        }
        
        virtual ~Resource()
        {
        }
};

#endif
