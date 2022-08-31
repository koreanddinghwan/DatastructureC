#include "bfs.h"

//Vertex와 가까운 노드 먼저 출력된다.

void bfs(LinkedGraph *LG, int VertexID)
{
	LinkedDeque *dq = createLinkedDeque();
	int visited[LG->maxVertexCount];
	memset(visited, 0, sizeof(int) * LG->maxVertexCount);
	DequeNode tmp;

	//맨 처음 vertex 방문처리
	visited[VertexID] = VISITED;
	tmp.data = VertexID;
	insertRearLD(dq, tmp);
	printf(ANSI_COLOR_RED " |V: %d " ANSI_COLOR_RESET, VertexID);

	while (isLinkedDequeEmpty(dq) == FALSE)
	{
		DequeNode *node = deleteFrontLD(dq);
		int vertexID = node->data;
		int iterLen = getLinkedListLength(LG->ppAdjEdge[vertexID]);
		free(node);
		for (int i = 0; i < iterLen; i++)
		{
			ListNode *node;

			node = getLLElement(LG->ppAdjEdge[vertexID], i);
			if (visited[node->vertexID] != VISITED)
			{
				visited[node->vertexID] = VISITED;
				printf(ANSI_COLOR_RED " |V: %d " ANSI_COLOR_RESET, node->vertexID);
				tmp.data = node->vertexID;
				insertRearLD(dq, tmp);
			}
		}
	}
}

void printer(ListNode node)
{
	printf(ANSI_COLOR_RED " |V: %d " ANSI_COLOR_RESET, node.vertexID);
	printf(ANSI_COLOR_BLUE "W : %d| " ANSI_COLOR_RESET, node.weight);
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
	bfs(LG, 3);
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
	bfs(LG, 3);
}

int main(void)
{

	undirected_test();
	printf("\n\n");
	directed_test();

	return 0;
}
