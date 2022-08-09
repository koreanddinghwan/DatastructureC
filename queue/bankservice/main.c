#include "bankservice.h"
#include "linkeddeque.h"

void initCustomer(LinkedDeque **pArrivalQueue)
{
	*pArrivalQueue = createLinkedDeque();

	insertCustomer(0, 3, *pArrivalQueue);
	insertCustomer(2, 2, *pArrivalQueue);
	insertCustomer(4, 1, *pArrivalQueue);
	insertCustomer(6, 1, *pArrivalQueue);
	insertCustomer(8, 3, *pArrivalQueue);
}

void launchBankProcess(LinkedDeque *pArrivalQueue)
{
	LinkedDeque *pWaitQueue = createLinkedDeque();
	DequeNode *serviceNode;

	int pServiceUserCount = 0;
	int pTotalWaitTime = 0;
	int t = 0;
	serviceNode = NULL;
	while (t < MAXTIME)
	{
		printf("=============currentTime : %d=============\n", t);
		processArrival(t, pArrivalQueue, pWaitQueue);
		serviceNode = processServiceNodeEnd(t, serviceNode, &pServiceUserCount, &pTotalWaitTime);
		if (serviceNode && serviceNode->data.status == end)
		{
			free(serviceNode);
			serviceNode = NULL;
		}
		if (!serviceNode)
			serviceNode = processServiceNodeStart(t, pWaitQueue);

		printf("below serviced customers\n");
		if (serviceNode)
			printSimCustomer(serviceNode->data);
		if (isLinkedDequeEmpty(pWaitQueue) == FALSE)
			pTotalWaitTime++;
		t++;
		printReport(pWaitQueue, pServiceUserCount, pTotalWaitTime);
		printf("=========================================\n");
		printf("=========================================\n\n\n");
	}
	deleteLinkedDeque(pWaitQueue);
	deleteLinkedDeque(pArrivalQueue);
}

int main(void)
{
	LinkedDeque *pArrivalQueue;

	initCustomer(&pArrivalQueue);
	iterDeque(pArrivalQueue, printSimCustomer);
	launchBankProcess(pArrivalQueue);
	return 0;
}
