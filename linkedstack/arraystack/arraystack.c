#include "arraystack.h"
#include <stdlib.h>

ArrayStack* createArrayStack(unsigned int maxElementCount)
{
	if (maxElementCount == 0)
		return (NULL);
	ArrayStack* rtn = calloc(1, sizeof(ArrayStack));
	if (!rtn)
		exit(ENOMEM);

	rtn->pTopElement = calloc(maxElementCount, sizeof(StackElement));
	rtn->maxElementCount = maxElementCount;
	if (!rtn->pTopElement)
		exit(ENOMEM);
	return (rtn);
}

int pushAS(ArrayStack* pStack, StackElement element)
{
	if (!pStack)
		exit(EFAULT);

	if (isArrayStackFull(pStack) == TRUE)
		return (FALSE);
	else
	{
		memcpy(pStack->pTopElement + pStack->currentElementCount, &element, sizeof(StackElement));
		pStack->currentElementCount++;
		return (TRUE);
	}
}

StackElement* popAS(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	else
	{
		StackElement* rtn = pStack->pTopElement + pStack->currentElementCount - 1;
		pStack->currentElementCount--;
		return (rtn);
	}
}

StackElement* peekAS(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	else
		return (pStack->pTopElement + pStack->currentElementCount - 1);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);
	free(pStack->pTopElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (pStack->currentElementCount == pStack->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}
