#include "mst.h"

void printer(ListNode node)
{
	printf(ANSI_COLOR_RED " |V: %d " ANSI_COLOR_RESET, node.vertexID);
	printf(ANSI_COLOR_BLUE "W : %d| " ANSI_COLOR_RESET, node.weight);
}

LinkedGraph *CreateUndirectedWeight(void)
{
	LinkedGraph *rtn;

	rtn = createLinkedGraph(6);
	addVertexLG(rtn, 0);
	addVertexLG(rtn, 1);
	addVertexLG(rtn, 2);
	addVertexLG(rtn, 3);
	addVertexLG(rtn, 4);
	addVertexLG(rtn, 5);

	addEdgewithWeightLG(rtn, 0, 1, 4);
	addEdgewithWeightLG(rtn, 0, 2, 3);
	addEdgewithWeightLG(rtn, 1, 2, 2);
	addEdgewithWeightLG(rtn, 2, 3, 1);
	addEdgewithWeightLG(rtn, 3, 4, 1);
	addEdgewithWeightLG(rtn, 3, 5, 5);
	addEdgewithWeightLG(rtn, 4, 5, 6);
	return (rtn);
}

int main(void)
{
	LinkedGraph *pGraph = CreateUndirectedWeight();

	printf(ANSI_COLOR_CYAN "!!!!!!!Origin Graph!!!!!!\n" ANSI_COLOR_RESET);
	displayLinkedGraph(pGraph, printer);
	printf("\n\n");

	Kruskal(pGraph);
	printf("\n\n");
	Prim(pGraph, 1);
	printf("\n\n");
}
