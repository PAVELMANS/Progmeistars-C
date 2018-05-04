#include <stdio.h>
#define FIDGE(k)  k+3.14159
#define PR(a) printf(#a "= %d\t",(int)(a))
#define PRINT1(a) PR(a); putchar('\n')
#define PRINT2(a,b) PR(a); PRINT1(b)
#define PRINT3(a,b,c) PR(a); PRINT2(b,c)
#define MAX(a,b) (a<b ? b : a)

int main()
{
   {
      int x=2;
      PRINT1( x*FIDGE(2) );
   }
   {
      int cel;
      for( cel=0; cel<=100; cel+=50 )
         PRINT2( cel, 9./5*cel+32 );
   }
   {
      int x=1, y=2;
      PRINT3( MAX(x++,y),x,y );
      PRINT3( MAX(x++,y),x,y );
   }
   return 0;
}
