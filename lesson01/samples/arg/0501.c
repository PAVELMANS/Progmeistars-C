#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Please enter your name.\n");
    exit(1);
  }
  printf("Hello, %s", argv[1]);

  return 0;
}
