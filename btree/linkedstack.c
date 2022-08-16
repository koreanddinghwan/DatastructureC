#include "linkedstack.h"

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
	{
		pStack->pTopElement = rtn;
		rtn->pLink = NULL;
	}
	else
	{
		rtn->pLink = pStack->pTopElement;
		pStack->pTopElement = rtn;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (isLinkedStackEmpty(pStack) == TRUE)
		return (NULL);
	else
	{
		StackNode *rtn;
		StackNode *nextTop;

		rtn = pStack->pTopElement;
		nextTop = rtn->pLink;
		rtn->pLink = NULL;
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
