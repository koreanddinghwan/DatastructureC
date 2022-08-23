#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include <errno.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
typedef struct ArrayGraphType
{
	int maxVertexCount;		// ?ִ? ???? ????
	int currentVertexCount;	// ???? ?????Ǵ? ?????? ????
	int graphType;			// ?׷??? ��??: 1-Undirected, 2-Directed
	int **ppAdjEdge;		// ???? ????�� ��?? 2???? array
	char *pVertex;			// ???? ????�� ��?? 1???? array
} ArrayGraph;

// ?׷??? ????
ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// ?׷??? ??��
void deleteArrayGraph(ArrayGraph* pGraph);

// ???? ?׷??? ???? ?Ǵ?
int isEmptyAG(ArrayGraph* pGraph);

// ???? ?߰?
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// ???? ?߰?
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ?????? ��ȿ?? ��??.
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// ???? ��??
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// ???? ��??
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// ?׷??? ��?? ????
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
