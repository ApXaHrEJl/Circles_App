#include "scan.h"
#include <stdio.h>

figure circle[10];

int main(int argc, char** argv)
{
    scan(argv[1], circle);
    return 0;
}
