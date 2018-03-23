#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int binsearch (int low, int high);

int main()
{
    time_t a;
    time(&a);
    srand(a); 
    int random_number = rand () % MAX + 1;
    printf("%d \n", random_number );
    printf("%d \n", binsearch(1, MAX) );
    scanf("%c", &a);
    return 0;
}

int binsearch (int low, int high)
{
    int x;
    int answer;
   
    while (low<=high) {
        x = (low+high)/2;
        printf (" Your number is \"<\" or \"=\" or \">\" than %i?", x);
        printf(" %c\n",  answer=getch() );
        if (answer=='<')
            high=x-1;
        else if (answer=='>')
            low=x+1;
        else
            return x;
   }
   printf(" CHEAT!!!\n");
   return 0;
}
