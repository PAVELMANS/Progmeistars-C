#include <stdio.h>
#define NEG(a) -a
#define weeks(mins) (days(mins)/7)
#define days(mins) (hours(mins)/24)
#define hours(mins) (mins/60)
#define mins(secs) (secs/60)
#define TAB(c,i,oi,t)  if(c=='\t')\
                         for(t=8-(i-oi-1)%8,oi=i; t; t--)\
                           putchar('.')
#define PR(a) printf(#a " = %d\t",(int)(a))
#define PRINT(a) PR(a); putchar('\n')

int main()
{
   {
      int x=1;
      PRINT( -NEG(-x) );
   }
   {
      PRINT( weeks(30240) );
      PRINT( weeks(32768) );
      PRINT( days(mins(86400)) );
   }
   {
      static char input[] = "\tABCD" "\tXYZ";
      char c;
      int i, oldi, temp;

      for( oldi=-1, i=0; (c=input[i])!='\0'; i++)
         if ( c<' ') TAB(c,i,oldi,temp);
         else putchar(c);
      putchar('\n');
   }
   return 0;
}
