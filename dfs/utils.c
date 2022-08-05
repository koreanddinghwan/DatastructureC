#include "utils.h"
#include "linkedstack.h"

void printCurMap(int *curpos)
{
	printf("--------------\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == curpos[1] && j == curpos[0])
				printf("P  ");
			else if (map[i][j] == 1)
				printf("🧱 ");
			else if (map[i][j] == 0)
				printf("🛣  ");
			else if (map[i][j] == 2)
				printf("⛔️ ");
			else 
				printf("%d  ", map[i][j]);
		}
		printf("\n");
	}
	printf("--------------\n");
}

void findCurPos(int *curpos)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == P)
			{
				curpos[0] = j;
				curpos[1] = i;
				printf("Current Person x : [%d], y : [%d]\n", curpos[0], curpos[1]);
			}
		}
	}
}

void findExitPos(int *exitpos)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == E)
			{
				exitpos[0] = j;
				exitpos[1] = i;
				printf("EXIT x : [%d], y : [%d]\n", exitpos[0], exitpos[1]);
			}
		}
	}
}

int isAvailPath(int originPos[2], StackNode *top, int DIROFSET[2])
{
	if (top->data.direction == DOWN && DIROFSET == UP)
		return (FALSE);
	else if (top->data.direction == UP && DIROFSET == DOWN)
		return (FALSE);
	else if (top->data.direction == LEFT && DIROFSET == RIGHT)
		return (FALSE);
	else if (top->data.direction == RIGHT && DIROFSET == LEFT)
		return (FALSE);

	int curpos[2] = {originPos[0], originPos[1] };

	curpos[0] += DIROFSET[0];
	curpos[1] += DIROFSET[1];

	if (curpos[0] < 0 || curpos[0] > 8 || curpos[1] < 0 || curpos[1] > 8)
		return (FALSE);
	if (map[curpos[1]][curpos[0]] == WALL)
		return (FALSE);
	if (map[curpos[1]][curpos[0]] == VISIT)
		return (FALSE);
	return (TRUE);
}

int checkPath(int curpos[2], LinkedStack *stack)
{
	for (int i = 0; i < NUM_DIRECTIONS; i++)
	{
		if (isAvailPath(curpos, peekLS(stack), DIRECTION_OFFSETS[i]) == TRUE)
			return TRUE;
	}
	return FALSE;
}

void getNextMapPosition(int *curpos, MapPosition *tmp, LinkedStack *stack)
{
	for (int i = 0; i < NUM_DIRECTIONS; i++)
	{
		if (isAvailPath(curpos, peekLS(stack), DIRECTION_OFFSETS[i]) == TRUE)
		{
			tmp->direction = DIRECTION_OFFSETS[i];
			tmp->x = curpos[0] + DIRECTION_OFFSETS[i][0];
			tmp->y = curpos[1] + DIRECTION_OFFSETS[i][1];
			return ;
		}
	}
}
