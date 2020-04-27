#include "scan.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void skip_char(size_t* i, char* line, size_t symb)
{
    while (line[*i] == symb) {
        *i += 1;
    }
}

size_t parse_coord(size_t* i, int* coord, char* line)
{
    *coord = atoi(&line[*i]);
    skip_char(i, line, 32);
    if (!(line[*i] == 48) && *coord == 0) {
        return 1;
    }
    skip_char(i, line, 45);
    while (isdigit(line[*i])) {
        *i += 1;
    }
    return 0;
}

size_t scan(char* str, figure* circle)
{
    FILE* file = fopen(str, "r");
    if (!file) {
        return 0;
    }
    size_t number = 0;
    char line[500];
    while (fgets(line, 500, file) != NULL) {
        size_t i = 0;
        while (line[i] != 40) {
            if (line[i] == 32) {
                i++;
                continue;
            }
            circle[number].name[i] = tolower(line[i]);
            i++;
        }
        i++;
        size_t bug = 0;
        bug = parse_coord(&i, &circle[number].x, line);
        bug = parse_coord(&i, &circle[number].y, line);
        skip_char(&i, line, 32);
        if (line[i] == 44) {
            i++;
        } else {
            return 0;
        }
        skip_char(&i, line, 32);
        circle[number].r = strtod(&line[i], NULL);
        size_t tochka = 0;
        while ((isdigit(line[i])) || ((line[i] == 46) && (tochka == 0))) {
            if (line[i] == 46) {
                tochka++;
            }
            i++;
        }
        skip_char(&i, line, 32);
        if ((circle[number].r <= 0)
            || (strcmp(circle[number].name, "circle") != 0) || (line[i] != 41)
            || (bug > 0) || (line[i + 1] != '\n')) {
            return 0;
        }
        number++;
    }
    fclose(file);
    return number;
}
