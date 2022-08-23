#include "linkeddeque.h"
#include <stdio.h>

void printhead(LinkedDeque *dq)
{
	printf("============\n");
	printf("cur cnt : %d\n", dq->currentElementCount);
	if (dq->pFrontNode)
		printf("front : %c\n", dq->pFrontNode->data);
	if (dq->pRearNode)
		printf("rear : %c\n", dq->pRearNode->data);
	printf("============\n");
}

void test1()
{
	LinkedDeque *ld = createLinkedDeque();
	DequeNode tmp;
	DequeNode *pop;

	tmp.data = 'A';
	printf("********insertfront A********\n");
	insertFrontLD(ld, tmp);
	printhead(ld);

	tmp.data = 'B';
	printf("********insertfront B********\n");
	insertFrontLD(ld, tmp);
	printhead(ld);

	tmp.data = 'C';
	printf("********insertrear C********\n");
	insertRearLD(ld, tmp);
	printhead(ld);

	printf("********deleteFront********\n");
	pop = deleteFrontLD(ld);
	free(pop);
	printhead(ld);

	printf("********deleteFront********\n");
	pop = deleteFrontLD(ld);
	free(pop);
	printhead(ld);

	printf("********deleteFront********\n");
	pop = deleteFrontLD(ld);
	free(pop);
	printhead(ld);

	deleteLinkedDeque(ld);
}

void test2()
{
	LinkedDeque *ld = createLinkedDeque();
	DequeNode *pop;

	DequeNode tmp;
	tmp.data = 'A';
	insertFrontLD(ld, tmp);
	tmp.data = 'B';
	insertFrontLD(ld, tmp);
	tmp.data = 'C';
	insertFrontLD(ld, tmp);
	printf("*******initial*******\n");
	printhead(ld);

	printf("********deleteRear********\n");
	pop = deleteRearLD(ld);
	free(pop);
	printhead(ld);

	printf("********deleteRear********\n");
	pop = deleteRearLD(ld);
	free(pop);
	printhead(ld);
	printf("********deleteRear********\n");
	pop = deleteRearLD(ld);
	free(pop);
	printhead(ld);
	deleteLinkedDeque(ld);
}

int  main(void)
{
	test1();
	test2();
	while (1)
		;
	return 0;
}
