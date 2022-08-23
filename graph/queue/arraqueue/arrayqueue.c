#include "arrayqueue.h"
#include <stdlib.h>

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *rtn;

	if (maxElementCount < 0)
		return (NULL);
	rtn = malloc(1 * sizeof(ArrayQueue));
	if (!rtn)
		exit(ENOMEM);
	rtn->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!rtn->pElement)
		exit(ENOMEM);
	rtn->maxElementCount = maxElementCount;
	rtn->currentElementCount = 0;
	rtn->front = -1;
	rtn->rear = -1;
	return (rtn);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		exit(EFAULT);
	if (isArrayQueueFull(pQueue) == TRUE)
		return (FALSE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	memcpy(pQueue->pElement + pQueue->rear, &element, sizeof(ArrayQueueNode));
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *rtn;

	if (!pQueue)
		exit(EFAULT);
	if (pQueue->currentElementCount == 0)
		return (NULL);
	if (pQueue->front == -1)
	{
		rtn = pQueue->pElement;
		pQueue->front = 1;
	}
	else
	{
		rtn = pQueue->pElement + pQueue->front;
		pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	}
	pQueue->currentElementCount--;
	if (isArrayQueueEmpty(pQueue) == TRUE)
	{
		pQueue->front = -1;
		pQueue->rear = -1;
	}
	return (rtn);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (!pQueue)
		exit(EFAULT);
	if (pQueue->currentElementCount == 0)
		return (NULL);
	if (pQueue->front == -1)
		return (pQueue->pElement);
	return (pQueue->pElement + pQueue->front);
}


void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (!pQueue)
		return ;
	if (pQueue->maxElementCount > 0)
		free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue)
	{
		if (pQueue->maxElementCount == pQueue->currentElementCount)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return -1;
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue)
	{
		if (pQueue->currentElementCount == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return -1;
}
