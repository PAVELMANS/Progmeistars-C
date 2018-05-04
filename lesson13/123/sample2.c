#include "defs.h"

#define LOW 0
#define HIGH 5
#define CHANGE 2

int i = LOW;

int main()
{
    auto int i = HIGH;
    reset(i/2);     PRINT1(d,i);
    reset(i=i/2);   PRINT1(d,i);
    i=reset(i/2);   PRINT1(d,i);
    workover(i);    PRINT1(d,i);
    return 0;
}

int workover(int i)
{
    i=(i%i) * ((i*i)/(2*i)+4);
    PRINT1(d,i);
    return(i);
}

int reset(int i)
{
    i = i<=CHANGE ? HIGH : LOW ;
    return(i);
}
