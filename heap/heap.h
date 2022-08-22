#ifndef HEAP_H
# define HEAP_H

#include "vector.h"

void make_heap(t_vector *vec);
void heapify_down(t_vector *vec, int i);
void heapify_up(t_vector *vec, int i);
void heap_push_back(t_vector *vec, t_data data);
void swap_data(t_data *a, t_data *b);

#endif
