#include "props.h"
#include <stdio.h>
#define N 1000

figure circle[N];

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Incorrect arguments\n");
        return 0;
    }
    size_t number = scan(argv[1], circle);
    if (number == 0) {
        printf("Invalid data\n");
        return 0;
    }
    for (int i = 0; i < number; i++) {
        printf("%d. circle (%d %d, %.1lf)\n",
               i + 1,
               circle[i].x,
               circle[i].y,
               circle[i].r);
        printf("\tperimeter = %.3lf\n", perimeter(circle, i));
        printf("\tarea = %.3lf\n", area(circle, i));
        crossing_check(circle, i, number);
    }
    return 0;
}
