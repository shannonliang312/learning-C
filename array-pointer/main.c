#include<stdio.h>

int main(int argc, char const *argv[])
{
  int a[] = {1,2,3,4,5};
  int *pa = NULL;

  pa = a;

  printf("a[1] = %d\n", *(pa+1));

  return 0;
}
