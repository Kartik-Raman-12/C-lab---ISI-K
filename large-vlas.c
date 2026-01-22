#include "common.h"

int main(int ac, char *av[])
{
    int i, n;

    scanf("%d", &n);
    printf("n = %d\n", n);

    int a[n], sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i] = i*i;
    printf("sum = %d\n", sum);
    return 0;
}
