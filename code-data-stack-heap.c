#include "common.h"

int dummy = 100;
int plusone(int x) { return x+1; }

int main(int ac, char *av[])
{
    char *a = "a", c = 'x', *cptr = &c;
    int n = 'a', *iptr;
    int (*f)(int, char **), (*g)(int);

    f = main; g = plusone;
    printf("Code: main at %p; plusone at %p\n", f, g);
    printf("Code: main at %p; plusone at %p\n", main, plusone);

    iptr = &dummy;
    *iptr = plusone(*iptr);
    printf("Data: dummy at %p; value of dummy = %d = %d\n", iptr, *iptr, dummy);

    if (NULL == (iptr = (int *) malloc(n*sizeof(int))))
        ERR_MESG("code-data-stack-heap: out of memory\n");
    printf("Heap: iptr points to memory allocated at %p\n", iptr);

    iptr = &n;
    *iptr = plusone(*iptr);
    printf("Stack: cptr at %p; value of cptr = %c = %c\n", cptr, *cptr, c);
    printf("Stack: n at %p; value of n = %d = %d\n", iptr, *iptr, n);
    printf("Stack: n at %p; value of n = %d = %d\n", iptr, *iptr, n);
    printf("Stack: iptr at %p; f at %p; g at %p\n", &iptr, &f, &g);

    getchar();
    printf("a is stored at %p\n", &a);
    printf("a points to %p\n", a);
    
    return 0;
}
