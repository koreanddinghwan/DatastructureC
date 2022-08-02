#include "finder.h"
#include "utils.h"

int isExitNow(int *curpos, int exitpos[2])
{
	if (curpos[0] == exitpos[0] && curpos[1] == exitpos[1])
		return (TRUE);
	else
		return (FALSE);
}

void moveBack(int *curpos, StackNode *poped)
{
	curpos[0] -= poped->data.direction[0];
	curpos[1] -= poped->data.direction[1];
}

void moveForward(int *curpos, StackNode *poped)
{
	curpos[0] += poped->data.direction[0];
	curpos[1] += poped->data.direction[1];
}

void moveAndPush(int *curpos, LinkedStack *stack) 
{
	StackNode tmp;

	getNextMapPosition(curpos, &(tmp.data), stack);
	moveForward(curpos, &tmp);
	pushLS(stack, tmp);
}

void finder(int *curpos, int exitpos[2], LinkedStack *stack)
{
	StackNode *poped;

	if (isExitNow(curpos, exitpos) == TRUE)//break
	{
		printf("GAME END\n");
		return ;
	}
	//
	while (checkPath(curpos, stack) == FALSE && (!isLinkedStackEmpty(stack)))
	{
		poped = popLS(stack);
		moveBack(curpos, poped);
		map[poped->data.y][poped->data.x] = VISIT;
		free(poped);
	}
	if (isLinkedStackEmpty(stack) == TRUE)
	{
		printf("길 없어용\n");
		return ;
	}
	moveAndPush(curpos, stack);
	printCurMap(curpos);
	finder(curpos, exitpos, stack);
}
