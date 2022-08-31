#include "mst.h"
#include "linkedgraph.h"
#include <stdio.h>

void initHeap(t_vector *heap, LinkedGraph *origin)
{
	t_data tmp;
	ListNode *node;

	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		//headernode
		node = &origin->ppAdjEdge[i]->headerNode;
		node = node->pLink;
		while (node)
		{
			tmp.fromVertex = i;
			tmp.toVertex = node->vertexID;
			tmp.weight = node->weight;
			min_heap_push_back(heap, tmp);
			node = node->pLink;
		}
	}
}

void Kruskal(LinkedGraph *origin)
{
	//heap
	t_vector *heap = vector(origin->currentVertexCount);
	initHeap(heap, origin);

	t_data tmp;
	int visited[origin->maxVertexCount];

	memset(visited, NOT_VISITED, sizeof(int) * origin->maxVertexCount);
	tmp = heap_get_min(heap);
	for (;tmp.weight != INT32_MAX;tmp= heap_get_min(heap))
	{
		if ((visited[tmp.toVertex] == VISITED) && (visited[tmp.fromVertex] == VISITED))
			continue;
		printf(ANSI_COLOR_YELLOW "|from: %d, to: %d|\n" ANSI_COLOR_RESET, tmp.toVertex, tmp.fromVertex);
		visited[tmp.toVertex] = VISITED;
		visited[tmp.fromVertex] = VISITED;
	}
}

typedef struct edge
{
	int from;
	int to;
	int weight;
	int VertexID;
} EDGE;

EDGE getMinEdgeNocycleInlst(ListNode *node, int *visited)
{
	EDGE rtn;

	rtn.weight = node->weight;
	rtn.VertexID = node->vertexID;
	node = node->pLink;
	while (node)
	{
		printf("checking node %d, %d\n", node->weight, node->vertexID);
		if ((node->weight <= rtn.weight) && (visited[node->vertexID] != VISITED))
		{
			rtn.VertexID = node->vertexID;
			rtn.weight = node->weight;
		}
		node = node->pLink;
	}
	return (rtn);
}

EDGE getNocycleMinEdgeInVisited(LinkedGraph *origin, int *visited)
{
	EDGE edge;
	EDGE rtn;

	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		if (visited[i] != VISITED)
			continue;
		edge = getMinEdgeNocycleInlst(origin->ppAdjEdge[i]->headerNode.pLink, visited);
		if (i == 0)
		{
			rtn = edge;
			continue;
		}
		if (edge.weight <= rtn.weight)
			rtn = edge;
		printf("====%d, %d\n", rtn.weight, rtn.VertexID);
	}
	return (rtn);
}

int checkRecurEnd(int max, int *visited)
{
	int cnt = 0;

	for (int i = 0; i < max; i++)
	{
		if (visited[i] == NOT_VISITED)
			return (FALSE);
	}
	return (TRUE);
}

void PrimUtil(LinkedGraph *origin, int *visited, int fromvertexID, int toVertexID)
{
	printf("call %d, %d ", fromvertexID, toVertexID);
	if (checkRecurEnd(origin->maxVertexCount, visited) == TRUE)
		return ;

	visited[toVertexID] = VISITED;
	printf("visited %d ", toVertexID);
	EDGE edge = getNocycleMinEdgeInVisited(origin, visited);
	PrimUtil(origin, visited, toVertexID, edge.VertexID);
}

void Prim(LinkedGraph *origin, int vertexID)
{
	int visited[origin->maxVertexCount];
	memset(visited, NOT_VISITED, sizeof(int) * origin->maxVertexCount);

	visited[vertexID] = VISITED;
	EDGE edge;

	edge = getNocycleMinEdgeInVisited(origin, visited);
	printf("%d\n", edge.VertexID);
	PrimUtil(origin, visited, vertexID, edge.VertexID);
}
