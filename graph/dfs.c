#include "dfs.h"

void printer(ListNode node)
{
	printf(ANSI_COLOR_RED " |V: %d " ANSI_COLOR_RESET, node.vertexID);
	printf(ANSI_COLOR_BLUE "W : %d| " ANSI_COLOR_RESET, node.weight);
}

void dfsUtil(LinkedGraph *pGraph, int *visited, int VertexID)
{
	if (visited[VertexID] == 1)
		return ;

	visited[VertexID] = 1;
	printf(ANSI_COLOR_RED " |V: %d " ANSI_COLOR_RESET, VertexID);

	int iterLen = getLinkedListLength(pGraph->ppAdjEdge[VertexID]);
	for (int i = 0; i < iterLen; i++)
	{
		ListNode *NextNode = getLLElement(pGraph->ppAdjEdge[VertexID], i);
		if (NextNode)
			dfsUtil(pGraph, visited, NextNode->vertexID);
	}
}

void dfs(LinkedGraph *pGraph, int VertexID)
{
	int visited[pGraph->maxVertexCount];

	printf("!!!!!!dfs!!!!!!\n");
	memset(visited, 0, sizeof(int) * pGraph->maxVertexCount);
	dfsUtil(pGraph, visited, VertexID);
}

void undirected_test(void)
{
	printf(ANSI_COLOR_CYAN "!!undirected_test!!\n" ANSI_COLOR_RESET);
	LinkedGraph *LG;

	LG = createLinkedGraph(6);
	addVertexLG(LG, 0);
	addVertexLG(LG, 1);
	addVertexLG(LG, 2);
	addVertexLG(LG, 3);
	addVertexLG(LG, 4);
	addVertexLG(LG, 5);
	addVertexLG(LG, 5);

	addEdgeLG(LG, 0, 1);
	addEdgeLG(LG, 0, 2);
	addEdgeLG(LG, 2, 3);
	addEdgeLG(LG, 1, 2);
	addEdgeLG(LG, 3, 4);
	addEdgeLG(LG, 4, 5);
	addEdgeLG(LG, 3, 5);

	displayLinkedGraph(LG, printer);
	dfs(LG, 1);
}

void directed_test(void)
{
	printf(ANSI_COLOR_CYAN "!!directed_test!!\n" ANSI_COLOR_RESET);
	LinkedGraph *LG;

	LG = createLinkedDirectedGraph(6);
	addVertexLG(LG, 0);
	addVertexLG(LG, 1);
	addVertexLG(LG, 2);
	addVertexLG(LG, 3);
	addVertexLG(LG, 4);
	addVertexLG(LG, 5);

	addEdgeLG(LG, 0, 1);
	addEdgeLG(LG, 1, 2);
	addEdgeLG(LG, 2, 0);
	addEdgeLG(LG, 2, 1);
	addEdgeLG(LG, 2, 3);
	addEdgeLG(LG, 3, 2);
	addEdgeLG(LG, 3, 4);
	addEdgeLG(LG, 4, 5);
	addEdgeLG(LG, 5, 3);
	displayLinkedGraph(LG, printer);
	dfs(LG, 1);
}

int main(void)
{


	undirected_test();
	printf("\n\n");
	directed_test();
	printf("\n\n");

	return 0;
}
