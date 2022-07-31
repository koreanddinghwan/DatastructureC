#include "linkedstack.h"
#include <stdlib.h>

LinkedStack* createLinkedStack()
{
	LinkedStack *rtn = calloc(1, sizeof(LinkedStack));
	if (!rtn)
		exit(ENOMEM);
	return (rtn);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	if (!pStack)
		exit(EFAULT);

	StackNode *rtn = calloc(1, sizeof(StackNode));
	if (!rtn)
		exit(ENOMEM);

	memcpy(rtn, &element, sizeof(StackNode));
	if (pStack->currentElementCount == 0)
		pStack->pTopElement = rtn;
	else
	{
		StackNode *beforetop = pStack->pTopElement;
		rtn->pLink = beforetop;
		pStack->pTopElement = rtn;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	StackNode *rtn;
	StackNode *nextTop;

	if (isLinkedStackEmpty(pStack) == TRUE)
		return (NULL);
	else
	{
		StackNode *rtn;
		StackNode *nextTop;

		rtn = pStack->pTopElement;
		nextTop = rtn->pLink;

		pStack->pTopElement = nextTop;
		pStack->currentElementCount--;
		return (rtn);
	}
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	StackNode *cur, *next;

	cur = pStack->pTopElement;
	while (cur)
	{
		next = cur->pLink;
		free(cur);
		cur = next;
	}
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
