#include "common.h"

int main(int ac, char *av[])
{
    int c, d, retval;

    while (1) {
        retval = scanf("%d", &d);
        if (retval < 0) return 0;
        if (retval > 0) printf("Read %d, return value = %d\n", d, retval);
        else if (retval == 0) {
            puts("Could not read integer, trying getchar");
            if (EOF == (c = getchar())) {
                puts("EOF");
                break;
            }
            else {
                printf("Skipping char %c (ASCII %d)\n", c, c);
#ifndef ONEBYONE
                char *s;

                printf("Reading multiple chars including %c (ASCII %d)\n", c, c);
                ungetc(c, stdin);
                retval = scanf("%ms", &s);
                printf("retval = %d; read %s (%lu chars)\n", retval, s, strlen(s));
                free(s);
#endif
            }
        }
    }

    return 0;
}
