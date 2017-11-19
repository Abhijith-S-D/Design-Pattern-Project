#ifndef Res
#define Res
class Resource
{
    int value;

    public:
        Resource()
        {
            value = 0;
        }

        void reset()
        {
            value = 0;
        }

        int getValue()
        {
            return value;
        }

        void setValue(int number)
        {
            value = number;
        }
};

#endif
