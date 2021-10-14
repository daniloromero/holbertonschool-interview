#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void copy_array(int *array, int i_start, int i_end, int *copy);
void merge_sort(int *array, size_t size);

#endif /* SORT_H */