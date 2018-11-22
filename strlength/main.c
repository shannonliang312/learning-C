#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  char s[128] = {0};
  char s1[128] = "liang";
  char s2[128] = "shengnan";

  strncpy(s, s2, strlen(s2));
  strncpy(s, s1, strlen(s1));
  
  printf("s = %s\n", s);
  printf("length = %d\n", strlen(s));

  char *p1 = NULL;
  char *p2 = s2;
  
  p1 = (char *)malloc(strlen(s1) + 1);

  strncpy(p1, s1, strlen(s1) + 1);
  printf("p1 = %s\n", p1);
  printf("p1 length = %d\n", strlen(p1));

  printf("s2 length = %d\n", sizeof(s2));
  printf("p2 length = %d\n", sizeof(p2));

  return 0;
}
