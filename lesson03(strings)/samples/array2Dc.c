#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

float average (int [], int);

int main()
{ int items[STUDENTS][EXAMS]={ {7,5,8,7}, {5,8,9,8}, {7,6,9,6} };
  printf("%6.2f\n", average(*items, STUDENTS));
  getchar();
  return 0;
}

float average (int a[], int students)
{   int i, j, sum=0;
    for (i=0 ; i< students; i++)  {
        for (j=0; j< EXAMS; j++)
            sum += a[i*EXAMS+j];
    }
    return (float) sum / (float) (students*EXAMS);
}

