#ifndef FINDER_H
# define FINDER_H

#include "linkedstack.h"
#include "mapdef.h"
#include "libft/libft.h"

#include <printf.h>
#include <fcntl.h>

extern int map[WIDTH][HEIGHT];

void findCurPos(int *curpos);
void findExitPos(int *exitpos);
void printCurMap(void);
void finder(int *curpos, int exitpos[2], LinkedStack *stack);
#endif
