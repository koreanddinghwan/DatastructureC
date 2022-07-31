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
	if (!rtn->pTopElement)
		exit(ENOMEM);
	return (rtn);
}

int pushLS(ArrayStack* pStack, StackElement element)
{
	if (!pStack)
		exit(EFAULT);

	if (isArrayStackFull(pStack) == TRUE)
		return (FALSE);
	else
	{
		memmove(pStack->pTopElement + 1, pStack->pTopElement, sizeof(StackElement) * pStack->currentElementCount);
		memcpy(pStack->pTopElement, &element, sizeof(StackElement));
		pStack->currentElementCount++;
		return (TRUE);
	}
}

StackElement* popLS(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	else
	{
		StackElement* rtn = pStack->pTopElement;


		pStack->currentElementCount--;
		return (rtn);
	}
}

StackElement* peekLS(ArrayStack* pStack)
{
	if (!pStack)
		exit(EFAULT);

	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	else
		return (pStack->pTopElement);
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
