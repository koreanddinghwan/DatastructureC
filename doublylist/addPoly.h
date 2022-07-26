#ifndef ADDPOLY_H
# define ADDPOLY_H
#include "doublylist.h"

int addPolyNodeLast(DoublyList *pList, float coef, int degree);
DoublyList *addPoly(DoublyList *a, DoublyList *b);
void PolyPrint(DoublyList *pList);
#endif
