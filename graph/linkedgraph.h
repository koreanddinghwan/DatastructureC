#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include "linkedlist.h"

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"
typedef struct LinkedGraphType
{
	int maxVertexCount;		// ?Ö´? ???? ????
	int currentVertexCount;	// ???? ?????Ç´? ?????? ????
	int currentEdgeCount;	// ???? ?????? ????.
	int graphType;			// ?×·??? Á¾??: 1-Undirected, 2-Directed
	LinkedList** ppAdjEdge;	// ???? ????À» À§?? ???? ????Æ® (??????)?? ?è¿­
	int *pVertex;			// ???? ????À» À§?? 1???? ?è¿­
} LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

void deleteLinkedGraph(LinkedGraph* pGraph);

int isEmptyLG(LinkedGraph* pGraph);

int addVertexLG(LinkedGraph* pGraph, int vertexID);

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(LinkedGraph* pGraph, int vertexID);

int removeVertexLG(LinkedGraph* pGraph, int vertexID);

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

int getEdgeCountLG(LinkedGraph* pGraph);

int getVertexCountLG(LinkedGraph* pGraph);

int getMaxVertexCountLG(LinkedGraph* pGraph);

int getMinVertexID(ListNode *node);
int getGraphTypeLG(LinkedGraph* pGraph);

void displayLinkedGraph(LinkedGraph* pGraph, void (*fp)(ListNode));
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define VISITED 1
#define NOT_VISITED 0

#define SUCCESS				1
#define FAIL				0
#define NOTFOUND           -1

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif
