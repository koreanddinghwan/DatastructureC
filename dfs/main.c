#include "finder.h"
#include "linkedstack.h"
#include <stdio.h>

int map[WIDTH][HEIGHT] =
{
	{P, 0, 1, 0, 1, 0, 1, 1},
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
	LinkedStack *stack = createLinkedStack();

	printCurMap();
	findCurPos(curpos);
	findExitPos(exitpos);
	printCurMap();



	return 0;
}
