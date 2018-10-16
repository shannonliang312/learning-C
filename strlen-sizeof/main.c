#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
  char ss[15] = "liangshengnan";
  int aa[10] = {1,2,3};

  printf("sizeof ss = %zd\n", sizeof(ss)); // sizeof标示有多少个bytes
  printf("strlen of ss = %zd\n", strlen(ss));

  printf("sizeof aa = %zd\n", sizeof(aa));

  return 0;
}
