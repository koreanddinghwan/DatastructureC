#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include <errno.h>

typedef struct ArrayGraphType
{
	int maxVertexCount;		// ?Ö´? ???? ????
	int currentVertexCount;	// ???? ?????Ç´? ?????? ????
	int graphType;			// ?×·??? Á¾??: 1-Undirected, 2-Directed
	int **ppAdjEdge;		// ???? ????À» À§?? 2???? array
	char *pVertex;			// ???? ????À» À§?? 1???? array
} ArrayGraph;

// ?×·??? ????
ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// ?×·??? ??Á¦
void deleteArrayGraph(ArrayGraph* pGraph);

// ???? ?×·??? ???? ?Ç´?
int isEmptyAG(ArrayGraph* pGraph);

// ???? ?ß°?
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// ???? ?ß°?
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ?????? À¯È¿?? Á¡??.
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// ???? Á¦??
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// ???? Á¦??
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// ?×·??? Á¤?? ????
void displayArrayGraph(ArrayGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
