#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
  int random = 0;
  srand((unsigned)time( 0 ));

  random = rand();

  printf("random = %d\n", random);

  return 0;
}
