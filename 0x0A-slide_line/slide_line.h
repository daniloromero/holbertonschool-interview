#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 4
#define SLIDE_RIGHT 5

void merge_line(int *line, size_t size);
void reverse_line(int *line, size_t size);
int slide(int *line, size_t size, int direction);
int slide_line(int *line, size_t size, int direction);


#endif /* SLIDE_LINE */
