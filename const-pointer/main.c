#include<stdio.h>

int main(int argc, char const *argv[])
{
  int a = 1;
  int b = 2;

  /* 指向的地址里的内容不能变 */
  const int *pa = &a;  // *p += 1; 不允许的操作
  
  /* 指向的地址不能变 */
  int * const pb = &b;  // pb = &a; 不允许的操作  

  printf("*pa = %d\n", *pa);
  printf("*pb = %d\n", *pb);
  
  return 0;
}
