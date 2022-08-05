#include "arrayqueue.h"
#include <printf.h>

void printQueueStatus(ArrayQueue *pQueue)
{
	printf("====queue's status====\n");
	printf("max : %d\n", pQueue->maxElementCount);
	printf("curCnt : %d\n", pQueue->currentElementCount);
	printf("front : %d\n", pQueue->front);
	printf("rear : %d\n", pQueue->rear);
	if (peekAQ(pQueue))
	{
		printf("peak : %d\n", peekAQ(pQueue)->data);
	}
	printf("======================\n");
}

void test1(void)
{
	printf("***********************\n");
	printf("test1 : enqueueAQ test\n");
	printf("***********************\n");
	ArrayQueue *que = createArrayQueue(5);
	ArrayQueueNode tmp;

	tmp.data = 5;
	enqueueAQ(que, tmp);
	tmp.data = 4;
	enqueueAQ(que, tmp);
	tmp.data = 3;
	enqueueAQ(que, tmp);
	tmp.data = 2;
	enqueueAQ(que, tmp);
	tmp.data = 1;
	enqueueAQ(que, tmp);
	tmp.data = 0;
	enqueueAQ(que, tmp);
	printQueueStatus(que);
}

void test2(void)
{
	printf("\n\n***********************\n");
	printf("test2 : dequeueAQ test\n");
	printf("***********************\n");
	ArrayQueue *que = createArrayQueue(5);
	ArrayQueueNode tmp;

	tmp.data = 5;
	enqueueAQ(que, tmp);
	tmp.data = 4;
	enqueueAQ(que, tmp);
	tmp.data = 3;
	enqueueAQ(que, tmp);
	tmp.data = 2;
	enqueueAQ(que, tmp);
	tmp.data = 1;
	enqueueAQ(que, tmp);
	tmp.data = 0;
	enqueueAQ(que, tmp);
	printQueueStatus(que);

	ArrayQueueNode *dequed;

	printf("****\ndeque 1\n****\n");
	dequed = dequeueAQ(que);
	printf("dequed : %d\n", dequed->data);
	printQueueStatus(que);
	
	printf("****\ndeque 2\n****\n");
	dequed = dequeueAQ(que);
	printf("dequed : %d\n", dequed->data);
	printQueueStatus(que);

	printf("****\ndeque 3\n****\n");
	dequed = dequeueAQ(que);
	printf("dequed : %d\n", dequed->data);
	printQueueStatus(que);

	printf("****\ndeque 4\n****\n");
	dequed = dequeueAQ(que);
	if (dequed)
		printf("dequed : %d\n", dequed->data);
	printQueueStatus(que);


	printf("****\ndeque 5\n****\n");
	dequed = dequeueAQ(que);
	if (dequed)
		printf("dequed : %d\n", dequed->data);
	printQueueStatus(que);

	printf("****\ndeque 6\n****\n");
	dequed = dequeueAQ(que);
	if (dequed)
		printf("dequed : %d\n", dequed->data);
	printQueueStatus(que);

	deleteArrayQueue(que);
}

void test3(void)
{
	printf("\n\n***********************\n");
	printf("test3 : dequeueAQ and enqueueAQ test\n");
	printf("***********************\n");
	ArrayQueue *que = createArrayQueue(5);
	ArrayQueueNode tmp;

	tmp.data = 5;
	enqueueAQ(que, tmp);
	tmp.data = 4;
	enqueueAQ(que, tmp);
	tmp.data = 3;
	enqueueAQ(que, tmp);
	tmp.data = 2;
	enqueueAQ(que, tmp);
	tmp.data = 1;
	enqueueAQ(que, tmp);
	tmp.data = 0;
	enqueueAQ(que, tmp);
	printQueueStatus(que);

	printf("****\ndeque 1\n****\n");
	dequeueAQ(que);
	printQueueStatus(que);
	
	printf("****\ndeque 2\n****\n");
	dequeueAQ(que);
	printQueueStatus(que);

	printf("****\ndeque 3\n****\n");
	dequeueAQ(que);
	printQueueStatus(que);

	printf("****\ndeque 4\n****\n");
	dequeueAQ(que);
	printQueueStatus(que);


	printf("****\ndeque 5\n****\n");
	dequeueAQ(que);
	printQueueStatus(que);

	printf("****\ndeque 6\n****\n");
	dequeueAQ(que);
	printQueueStatus(que);

	printf("****\nenqueue 1\n****\n");
	tmp.data = 7;
	enqueueAQ(que, tmp);
	printQueueStatus(que);


	printf("****\nenqueue 2\n****\n");
	tmp.data = 8;
	enqueueAQ(que, tmp);
	printQueueStatus(que);


	printf("****\nenqueue 3\n****\n");
	tmp.data = 9;
	enqueueAQ(que, tmp);
	printQueueStatus(que);

	printf("****\nenqueue 4\n****\n");
	tmp.data = 10;
	enqueueAQ(que, tmp);
	printQueueStatus(que);

	printf("****\nenqueue 5\n****\n");
	tmp.data = 11;
	enqueueAQ(que, tmp);
	printQueueStatus(que);


	printf("****\nenqueue 6\n****\n");
	tmp.data = 12;
	enqueueAQ(que, tmp);
	printQueueStatus(que);

	deleteArrayQueue(que);
}

void test4(void)
{
	printf("\n\n***********************\n");
	printf("test4 : dequeueAQ and enqueueAQ combine test\n");
	printf("***********************\n");
	ArrayQueue *que = createArrayQueue(4);
	ArrayQueueNode tmp;
	
	tmp.data = 0;
	enqueueAQ(que, tmp);
	printQueueStatus(que);
	tmp.data = 1;
	enqueueAQ(que, tmp);
	printQueueStatus(que);
	tmp.data = 2;
	enqueueAQ(que, tmp);
	printQueueStatus(que);
	tmp.data = 3;
	enqueueAQ(que, tmp);
	printQueueStatus(que);
	dequeueAQ(que);
	printQueueStatus(que);
	printf("peek : %d\n", peekAQ(que)->data);
	tmp.data = 4;
	enqueueAQ(que, tmp);
	printQueueStatus(que);
	dequeueAQ(que);
	printQueueStatus(que);
	dequeueAQ(que);
	printQueueStatus(que);
	dequeueAQ(que);
	printQueueStatus(que);
	dequeueAQ(que);
	printQueueStatus(que);

	dequeueAQ(que);
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}
