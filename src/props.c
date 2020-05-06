#include "scan.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

double perimeter(figure* circle, size_t n)
{
    return (2 * M_PI * circle[n].r);
}

double area(figure* circle, size_t n)
{
    return (M_PI * pow(circle[n].r, 2));
}

size_t crossing(figure* circle, size_t n, size_t i)
{
    if ((sqrt(pow(circle[n].x, 2) + pow(circle[n].y, 2))
         + sqrt(pow(circle[i].x, 2) + pow(circle[i].y, 2)))
        <= (circle[n].r + circle[i].r)) {
        return 1;
    }
    return 0;
}

void crossing_check(figure* circle, size_t n, size_t number)
{
    size_t crs = 0;
    for (size_t i = 0; i < number; i++) {
        if (i != n) {
            if (crossing(circle, n, i) == 1) {
                printf("\t\t%d. circle\n", i);
                crs = 1;
            }
        }
    }
    if (crs == 0) {
        printf("\t\tnone\n");
    }
}

