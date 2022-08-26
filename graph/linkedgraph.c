#include "linkedgraph.h"
#include "linkedlist.h"
#include <stdlib.h>

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *rtn = malloc(sizeof(LinkedGraph));
	if (!rtn)
		exit(ENOMEM);
	rtn->ppAdjEdge = malloc(sizeof(LinkedList *) * maxVertexCount);
	if (!rtn->ppAdjEdge)
		exit(ENOMEM);
	for (int i = 0; i < maxVertexCount; i++)
		rtn->ppAdjEdge[i] = createLinkedList();
	rtn->pVertex = malloc(sizeof(int) * maxVertexCount);
	if (!rtn->pVertex)
		exit(ENOMEM);
	rtn->maxVertexCount = maxVertexCount;
	rtn->currentVertexCount = 0;
	rtn->currentEdgeCount = 0;
	rtn->graphType = GRAPH_UNDIRECTED;
	return (rtn);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *rtn = malloc(sizeof(LinkedGraph));
	if (!rtn)
		exit(ENOMEM);
	rtn->ppAdjEdge = malloc(sizeof(LinkedList *) * maxVertexCount);
	if (!rtn->ppAdjEdge)
		exit(ENOMEM);
	for (int i = 0; i < maxVertexCount; i++)
		rtn->ppAdjEdge[i] = createLinkedList();
	rtn->pVertex = malloc(sizeof(int) * maxVertexCount);
	if (!rtn->pVertex)
		exit(ENOMEM);
	rtn->maxVertexCount = maxVertexCount;
	rtn->currentVertexCount = 0;
	rtn->currentEdgeCount = 0;
	rtn->graphType = GRAPH_DIRECTED;
	return (rtn);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (0);
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph || pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);

	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
			checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);

	int pos;
	ListNode elem;

	elem.weight = 1;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		//from->to
		elem.vertexID = toVertexID;
		pos = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
		if (pos != NOTFOUND)
			return (FALSE);
		addLLElement(pGraph->ppAdjEdge[fromVertexID], pos, elem);
		pGraph->currentEdgeCount++;

		//to->from
		elem.vertexID = fromVertexID;
		pos = findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		if (pos != NOTFOUND)
			return (FALSE);
		addLLElement(pGraph->ppAdjEdge[fromVertexID], pos, elem);
		pGraph->currentEdgeCount++;
	}
	else
	{
		elem.vertexID = toVertexID;
		pos = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
		if (pos != NOTFOUND)
			return (FALSE);
		addLLElement(pGraph->ppAdjEdge[fromVertexID], pos, elem);
		pGraph->currentEdgeCount++;
	}
	return (TRUE);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
			checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);

	int pos;
	ListNode elem;

	elem.weight = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		//from->to
		elem.vertexID = toVertexID;
		pos = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
		if (pos != NOTFOUND)
			return (FALSE);
		addLLElement(pGraph->ppAdjEdge[fromVertexID], pos, elem);
		pGraph->currentEdgeCount++;

		//to->from
		elem.vertexID = fromVertexID;
		pos = findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		if (pos != NOTFOUND)
			return (FALSE);
		addLLElement(pGraph->ppAdjEdge[fromVertexID], pos, elem);
		pGraph->currentEdgeCount++;
	}
	else
	{
		elem.vertexID = toVertexID;
		pos = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
		if (pos != NOTFOUND)
			return (FALSE);
		addLLElement(pGraph->ppAdjEdge[fromVertexID], pos, elem);
		pGraph->currentEdgeCount++;
	}
	return (TRUE);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	return (TRUE);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph,vertexID) == FALSE)
		return (FALSE);


	return (TRUE);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph,fromVertexID) == FALSE ||
			checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);

	return (TRUE);
}

//vertex 가진 list의 node 삭제
void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int pos = findGraphNodePosition(pList, delVertexID);

	if (pos != NOTFOUND)
		removeLLElement(pList, pos);
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode *node;

	node = pList->headerNode.pLink;
	int cnt = 0;
	while (node)
	{
		if (node->vertexID == vertexID)
			return (cnt);
		node = node->pLink;
		cnt++;
	}
	return (NOTFOUND);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return 0;
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (0);
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (0);
	else
		return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (pGraph->graphType == GRAPH_DIRECTED)
		return (GRAPH_DIRECTED);
	else
		return (GRAPH_UNDIRECTED);
}

void displayLinkedGraph(LinkedGraph* pGraph);
