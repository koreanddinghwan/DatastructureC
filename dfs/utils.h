#ifndef UTILS_H
# define UTILS_H

#include "linkedstack.h"
#include "mapdef.h"
#include <printf.h>

extern int map[WIDTH][HEIGHT];

void findCurPos(int *curpos);
void findExitPos(int *exitpos);
void printCurMap(int *curpos);
int checkPath(int curpos[2], LinkedStack *stack);
void getNextMapPosition(int *curpos, MapPosition *tmp, LinkedStack *stack);
#endif
