#include "scan.h"
#include <stdio.h>

void scan(char* str, figure* circle)
{
    FILE* file = fopen(str, "r");
    int i = 0;
    while (fscanf(file,
                  "%s (%d %d, %d)",
                  circle[i].name,
                  &circle[i].p[0],
                  &circle[i].p[1],
                  &circle[i].p[2])
           != EOF) {
        i++;
    }
}
