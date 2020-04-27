#ifndef H_SCAN
#define H_SCAN
#include <stddef.h>

typedef struct {
    char name[7];
    int x, y;
    double r;
} figure;

void skip_char(size_t* i, char* line, size_t symb);

int check_line(char* line, int* number, figure* circle);

size_t parse_coord(size_t* i, int* coord, char* line);

size_t scan(char* str, figure* circle);
#endif
