#include "defs.h"

int i=0;

int main()  
{
    auto int i=1;
    PRINT1(d,i);
    {
        int i = 2;
        PRINT1(d,i);
        {
            i += 1;
            PRINT1(d,i);
        }
        PRINT1(d,i);
    }
    PRINT1(d,i);
    return 0;
}
