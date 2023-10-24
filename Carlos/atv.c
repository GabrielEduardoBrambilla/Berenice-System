#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b, i, menor;
  short t[11];
  scanf("%d %d", a, b);

  for (i = 1; i < 10; i++)
  {
    t[1] = ((a * b) / 10) * i;
    printf("%d\n", t[i]);
  }

  return 0;
}