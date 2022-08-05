#include "finder.h"
#include "utils.h"
#include "linkedstack.h"
#include <stdio.h>

int map[WIDTH][HEIGHT] =
{
	{P, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 1, 0, E},
};

void initData(int *curpos, int *exitpos, StackNode *tmp, LinkedStack **stack)
{

	findCurPos(curpos);
	findExitPos(exitpos);

	*stack = createLinkedStack();
	tmp->data.x = curpos[0];
	tmp->data.y = curpos[1];
	pushLS(*stack, *tmp);
}

int main(void)
{
	int curpos[2];
	int exitpos[2];
	StackNode tmp;
	LinkedStack *stack;

	initData(curpos, exitpos, &tmp, &stack);
	printCurMap(curpos);
	finder(curpos, exitpos, stack);
	deleteLinkedStack(stack);
	return 0;
}
