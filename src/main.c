#include "scan.h"
#include <stdio.h>
#define N 1000

figure circle[N];

int main(int argc, char** argv)
{
    scan(argv[1], circle);
    return 0;
}
