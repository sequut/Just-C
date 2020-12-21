#define _CRT_SECURE_NO_WARINNGS
#include <stdio.h>
#include <math.h>

int main(){
  int x;
  int y;
  int z;
  scanf("%d %d %d", &x, &y, &z);
  
  if (x<=0)
    printf("%d", -1);

  else if (y<=0)
    printf("%d", -2);

  else if (z<=0)
    printf("%d", -3);

  else
    printf("%d", 2*(x*y+y*z+x*z));

  return 0;
}
