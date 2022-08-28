#include "linkedgraph.h"

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

	addEdgeLG(LG, 0, 1);
	addEdgeLG(LG, 0, 2);
	addEdgeLG(LG, 2, 3);
	addEdgeLG(LG, 1, 2);
	addEdgeLG(LG, 3, 4);
	addEdgeLG(LG, 4, 5);
	addEdgeLG(LG, 3, 5);

	displayLinkedGraph(LG, printer);
}

void directed_test(void)
{
	printf(ANSI_COLOR_CYAN "!!undirected_test!!\n" ANSI_COLOR_RESET);
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
}

void directedunwieght_test(void)
{
	printf(ANSI_COLOR_CYAN "!!directedunwieght_test!!\n" ANSI_COLOR_RESET);
	LinkedGraph *LG;

	LG = createLinkedDirectedGraph(6);
	addVertexLG(LG, 0);
	addVertexLG(LG, 1);
	addVertexLG(LG, 2);
	addVertexLG(LG, 3);
	addVertexLG(LG, 4);
	addVertexLG(LG, 5);

	addEdgewithWeightLG(LG, 0, 1, 4);
	addEdgewithWeightLG(LG, 1, 2, 1);
	addEdgewithWeightLG(LG, 2, 1, 3);
	addEdgewithWeightLG(LG, 2, 0, 2);
	addEdgewithWeightLG(LG, 2, 3, 2);
	addEdgewithWeightLG(LG, 3, 2, 1);
	addEdgewithWeightLG(LG, 3, 4, 1);
	addEdgewithWeightLG(LG, 4, 5, 1);
	addEdgewithWeightLG(LG, 5, 3, 2);
	displayLinkedGraph(LG, printer);
}



int main(void)
{
	undirected_test();
	printf("\n\n");
	directed_test();
	printf("\n\n");
	directedunwieght_test();
	printf("\n\n");
	return 0;
}
