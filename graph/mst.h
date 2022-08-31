#ifndef MST_H
# define MST_H

#include "linkedgraph.h"
#include "heap.h"
#include "vector.h"

void Kruskal(LinkedGraph *origin);
void Prim(LinkedGraph *origin, int vertexID);

#endif
