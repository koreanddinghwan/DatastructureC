#ifndef HEAP_H
# define HEAP_H
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#include "vector.h"

void min_heap_push_back(t_vector *vec, t_data data);
void swap_data(t_data *a, t_data *b);
void min_heapify(t_vector *vec, int i);

#endif
