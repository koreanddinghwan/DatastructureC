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





//////////Prim
typedef struct edge
{
	int from;
	int to;
	int weight;
	int VertexID;
} EDGE;

EDGE getMinWeightEdgeList(LinkedList *list, int *visited)
{
	ListNode *node;
	EDGE rtn;

	node = list->headerNode.pLink;
	rtn.weight = INT32_MAX;
	rtn.VertexID = node->vertexID;
	while (node)
	{
		if (visited[node->vertexID] == VISITED)
		{
			node = node->pLink;
			continue;
		}
		if (!node)
			return (rtn);
		if (rtn.weight >= node->weight)
		{
			rtn.weight = node->weight;
			rtn.VertexID = node->vertexID;
		}
		node = node->pLink;
	}
	return (rtn);
}

EDGE getNocycleMinEdgeInVisited(LinkedGraph *origin, int *visited)
{
	int actualRoop = 0;
	EDGE edge;
	EDGE rtn;

	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		//list가 비어있으면 다음거로
		if (origin->ppAdjEdge[i]->currentElementCount == 0)
			continue;
		//방문안했던 노드도 배제
		if (visited[i] == FALSE)
			continue;
		//방문했던 노드들의 헤더노드를 전달.
		edge = getMinWeightEdgeList(origin->ppAdjEdge[i], visited);
		if (actualRoop == 0)
			rtn = edge;
		if (rtn.weight >= edge.weight)
			rtn = edge;
		actualRoop++;
	}
	return (rtn);
}

int checkRecurEnd(int max, int *visited)
{
	int cnt = 0;

	for (int i = 0; i < max; i++)
	{
		if (visited[i] == VISITED)
			cnt++;
	}
	if (cnt == max)
		return (TRUE);
	else
		return (FALSE);
}

void PrimUtil(LinkedGraph *origin, int *visited, int fromvertexID, int toVertexID)
{
	visited[toVertexID] = VISITED;
	printf(ANSI_COLOR_YELLOW"visited %d \n" ANSI_COLOR_RESET, toVertexID);

	if (checkRecurEnd(origin->maxVertexCount, visited) == TRUE)
		return ;
	EDGE edge = getNocycleMinEdgeInVisited(origin, visited);
	PrimUtil(origin, visited, toVertexID, edge.VertexID);
}

void Prim(LinkedGraph *origin, int vertexID)
{
	int visited[origin->maxVertexCount];
	memset(visited, NOT_VISITED, sizeof(int) * origin->maxVertexCount);

	visited[vertexID] = VISITED;
	printf(ANSI_COLOR_YELLOW"visited %d \n" ANSI_COLOR_RESET, vertexID);
	EDGE edge;

	//visited한 vertext와 연결된 edge중 가중치 가장 작은 edge선택
	edge = getNocycleMinEdgeInVisited(origin, visited);
	PrimUtil(origin, visited, vertexID, edge.VertexID);
}

/////////////////////////////////////
///
///

void init(LinkedGraph *origin, int *visited, int *distance)
{
	ListNode *node;

	for (int i = 0; i < origin->maxVertexCount; i++)
		distance[i] = INT32_MAX;
	memset(visited, NOT_VISITED, sizeof(int) * origin->maxVertexCount);
}

void updateDistance(int VertexID, LinkedGraph *origin, int *distance, int *visited)
{
	ListNode *node= origin->ppAdjEdge[VertexID]->headerNode.pLink;

	while (node)
	{
		if (visited[node->vertexID] != VISITED && (node->weight + distance[VertexID] < distance[node->vertexID]))
			distance[node->vertexID] = node->weight + distance[VertexID];
		node = node->pLink;
	}
}

int getMinDistIdx(int *distance, int *visited, LinkedGraph *origin)
{
	int minDist = INT32_MAX;
	int minDistIdx = 0;

	for (int i = 0;i < origin->maxVertexCount; i++)
	{
		//방문한 노드는 대상이 아님
		if (visited[i] == VISITED)
			continue;
		//방문하지 않은 노드 중, 거리가 제일 짧은 것 선택
		if (distance[i] < minDist)
		{
			minDist = distance[i];
			minDistIdx = i;
		}
	}
	return (minDistIdx);
}

void Dijkstra(LinkedGraph *origin, int VertexID)
{
	int visited[origin->maxVertexCount];
	int distance[origin->maxVertexCount];
	int curCnt = 0;

	printf(ANSI_COLOR_BLUE"!!!Dijkstra!!!\n"ANSI_COLOR_RESET);
	init(origin, visited, distance);
	//최초vertexID의 거리는 0
	distance[VertexID] = 0;
	//vertex 방문처리
	//visited가 모두 채워질때까지 반복
	while (curCnt < origin->maxVertexCount)
	{
		//Vertex 방문처리
		visited[VertexID] = VISITED;
		//Vertex ID에 대해 연결된 노드들 거리 없데이트
		updateDistance(VertexID, origin, distance, visited);
		for (int i = 0; i < origin->maxVertexCount; i++)
			printf("| %d |", distance[i]);
		printf("\n");
		//Distance배열에서 가장 작은 거리를 가진 값의 인덱스(Vertex) 추출
		VertexID = getMinDistIdx(distance, visited, origin);
		printf("next vertexID : %d \n", VertexID);
		curCnt++;
	}
	for (int i = 0; i < origin->maxVertexCount; i++)
		printf(ANSI_COLOR_BLUE "Vertex: %d distance: %d\n"ANSI_COLOR_RESET, i, distance[i]);
}

//Floyd

void InitMap(LinkedGraph *origin, int map[origin->maxVertexCount][origin->maxVertexCount])
{
	//map init
	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		for (int j =0; j < origin->maxVertexCount; j++)
		{
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = 100000000;
		}
	}

	ListNode *node;
	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		node = origin->ppAdjEdge[i]->headerNode.pLink;
		while (node)
		{
			map[i][node->vertexID] = node->weight;
			node = node->pLink;
		}
	}
}

void Floyd(LinkedGraph *origin)
{
	int map[origin->maxVertexCount][origin->maxVertexCount];

	InitMap(origin, map);


	//roop
	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		for (int j = 0; j < origin->maxVertexCount; j++)
		{
			for (int k = 0; k < origin->maxVertexCount; k++)
			{
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}

	for (int i = 0; i < origin->maxVertexCount; i++)
	{
		for (int j = 0; j  < origin->maxVertexCount; j++)
		{
			printf(ANSI_COLOR_YELLOW "| %d |" ANSI_COLOR_RESET, map[i][j]);
		}
		printf("\n");
	}
}
