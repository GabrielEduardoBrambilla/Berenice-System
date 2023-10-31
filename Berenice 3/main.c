#include <stdio.h>
#include <stdlib.h>

int main()
{
  int v, n, i, menor;
  int result;
  scanf("%d %d", &v, &n);

  for (i = 1; i < 10; i++)
  {
    result = (((v * n) / 10) * i) +1;
    printf("%d\n", result);
  }

  return 0;
}
