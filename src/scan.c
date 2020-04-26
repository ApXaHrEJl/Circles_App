#include "scan.h"
#include <stdio.h>

void check_line(int* i, int debug)
{
    if (debug != 4) {
        if (debug == EOF) {
            return;
        } else {
            printf("Invalid data!\n");
            *i = 0;
            return;
        }
    }
    *i++;
}

void scan(char* str, figure* circle)
{
    FILE* file = fopen(str, "r");
    int i = 0;
    int debug;
    do {
        debug = fscanf(
                file,
                "%s (%d %d, %d)",
                circle[i].name,
                &circle[i].p[0],
                &circle[i].p[1],
                &circle[i].p[2]);
        check_line(&i, debug);
    } while (debug == 4);
}
