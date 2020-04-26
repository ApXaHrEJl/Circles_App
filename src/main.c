#include "scan.h"
#include <stdio.h>
#define N 1000

figure circle[N];

int main(int argc, char** argv)
{
    int number = scan(argv[1], circle);
    if (number != 0) {
        for (int i = 0; i < number; i++) {
            printf("%d. circle (%d %d, %d)\n",
                   i,
                   circle[i].p[0],
                   circle[i].p[1],
                   circle[i].p[2]);
        }
    }
    return 0;
}
