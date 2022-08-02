#include "finder.h"

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


void printCurMap(void)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == P)
				printf("P  ");
			else 
				printf("%d  ", map[i][j]);
		}
		printf("\n");
	}
}

int isExitNow(int *curpos, int exitpos[2])
{
	if (curpos[0] == exitpos[0] && curpos[1] == exitpos[1])
		return (TRUE);
	else
		return (FALSE);
}

int isAvailPath(int originPos[2], int DIROFSET[2])
{
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

int isNonePath(int curpos[2], int exitpos[2], LinkedStack *stack)
{
	for (int i = 0; i < NUM_DIRECTIONS; i++)
	{
		if (isAvailPath(curpos, DIRECTION_OFFSETS[i]) == TRUE)
			return TRUE;
	}
	return FALSE;
}

void move(int *curpos, LinkedStack *stack)
{
	
}

void finder(int *curpos, int exitpos[2], LinkedStack *stack)
{
	if (isExitNow(curpos, exitpos) == TRUE)//break
	{
		printf("GAME END\n");
		return ;
	}
	//
	if (isNonePath(curpos, exitpos, stack) == TRUE)
	{
		printf("길 없썽\n");
		return ;
	}
}
