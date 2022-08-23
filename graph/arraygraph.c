#include "arraygraph.h"
#include <stdlib.h>
#include <sys/errno.h>

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *rtn;

	rtn = malloc(sizeof(ArrayGraph));
	if (!rtn)
		exit(ENOMEM);
	rtn->ppAdjEdge = malloc(sizeof(int *) * maxVertexCount);
	if (!rtn->ppAdjEdge)
		exit(ENOMEM);
	for (int i = 0; i < maxVertexCount; i++)
	{
		rtn->ppAdjEdge[i] = malloc(sizeof(int) * maxVertexCount);
		if (!rtn->ppAdjEdge[i])
			exit(ENOMEM);
	}
	rtn->pVertex = calloc(sizeof(char) , maxVertexCount);
	if (!rtn->pVertex)
		exit(ENOMEM);
	rtn->maxVertexCount = maxVertexCount;
	rtn->currentVertexCount = 0;
	rtn->graphType = GRAPH_UNDIRECTED;
	return (rtn);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *rtn;

	rtn = malloc(sizeof(ArrayGraph));
	if (!rtn)
		exit(ENOMEM);
	rtn->ppAdjEdge = malloc(sizeof(int *) * maxVertexCount);
	if (!rtn->ppAdjEdge)
		exit(ENOMEM);
	for (int i = 0; i < maxVertexCount; i++)
	{
		rtn->ppAdjEdge[i] = malloc(sizeof(int) * maxVertexCount);
		if (!rtn->ppAdjEdge[i])
			exit(ENOMEM);
	}
	rtn->pVertex = malloc(sizeof(char) * maxVertexCount);
	if (!rtn->pVertex)
		exit(ENOMEM);
	rtn->maxVertexCount = maxVertexCount;
	rtn->currentVertexCount = 0;
	rtn->graphType = GRAPH_DIRECTED;
	return (rtn);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	return (pGraph->currentVertexCount ? TRUE : FALSE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph->maxVertexCount == pGraph->currentVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);

	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
			checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);

	if (pGraph->graphType == GRAPH_DIRECTED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	}
	else
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	}
	return (TRUE);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
			checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);

	if (pGraph->graphType == GRAPH_DIRECTED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight; 
	}
	else
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight; 
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight; 
	}
	return (TRUE);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	return (TRUE);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE)
		return (FALSE);

	pGraph->pVertex[vertexID] = NOT_USED;
	for (int i = 0; i < pGraph->currentVertexCount; i++)
		pGraph->ppAdjEdge[i][vertexID] = 0;
	for (int i = 0; i < pGraph->currentVertexCount; i++)
		pGraph->ppAdjEdge[vertexID][i] = 0;
	return (TRUE);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
			checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);

	if (pGraph->graphType == GRAPH_DIRECTED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	}
	else
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	}
	return (TRUE);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	printf(ANSI_COLOR_GREEN"=====================\n"ANSI_COLOR_RESET);
	for (int i =0; i < pGraph->currentVertexCount; i++)
	{
		for (int j = 0; i <pGraph->currentVertexCount; j++)
		{
			printf(ANSI_COLOR_YELLOW"%d " ANSI_COLOR_RESET, pGraph->ppAdjEdge[i][j]);
		}
	}
	printf(ANSI_COLOR_GREEN"=====================\n"ANSI_COLOR_RESET);
}
