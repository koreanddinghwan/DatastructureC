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



int main(void)
{
	int curpos[2];
	int exitpos[2];
	StackNode tmp;
	LinkedStack *stack = createLinkedStack();

	findCurPos(curpos);
	tmp.data.x = curpos[0];
	tmp.data.y = curpos[1];
	pushLS(stack, tmp);
	findExitPos(exitpos);
	printCurMap(curpos);

	finder(curpos, exitpos, stack);
	deleteLinkedStack(stack);
	return 0;
}
