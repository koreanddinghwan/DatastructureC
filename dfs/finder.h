#ifndef FINDER_H
# define FINDER_H

#include "linkedstack.h"
#include "mapdef.h"
#include "libft/libft.h"
#include "utils.h"

#include <printf.h>

extern int map[WIDTH][HEIGHT];

void finder(int *curpos, int exitpos[2], LinkedStack *stack);
#endif
