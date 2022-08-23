#include "bankservice.h"
#include "linkeddeque.h"

void insertCustomer(int arrivalTime, int serviceTime, LinkedDeque *pqueue)
{
	DequeNode tmp;

	tmp.data.status = arrival;
	tmp.data.arrivalTime = arrivalTime;
	tmp.data.serviceTime = serviceTime;
	tmp.data.startTime = -1;
	tmp.data.endTime = -1;
	insertRearLD(pqueue, tmp);
}

void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
	if (isLinkedDequeEmpty(pArrivalQueue) == TRUE)
		return ;
	if (peekFrontLD(pArrivalQueue)->data.arrivalTime == currentTime)
	{
		DequeNode *poped = deleteFrontLD(pArrivalQueue);
		poped->data.status = arrival;
		insertRearLD(pWaitQueue, *poped);
		free(poped);
	}
}

DequeNode *processServiceNodeStart(int curTime, LinkedDeque *pWaitQueue)
{
	DequeNode *rtn;

	if (isLinkedDequeEmpty(pWaitQueue) == TRUE)
		return (NULL);
	rtn = deleteFrontLD(pWaitQueue);
	rtn->data.status = start;
	rtn->data.startTime = curTime;
	rtn->data.endTime = curTime + rtn->data.serviceTime;
	return (rtn);
}

DequeNode *processServiceNodeEnd(int curTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (!pServiceNode)
		return (NULL);
	if (pServiceNode->data.endTime == curTime)
	{
		pServiceNode->data.status = end;
		(*pServiceUserCount)++;
		*pTotalWaitTime = 0;
	}
	return (pServiceNode);
}

void printSimCustomer(SimCustomer customer)
{
	printf("===== customer status =====\n");
	printf("customer status : ");
	if (customer.status == arrival)
		printf("arrival\n");
	else if (customer.status == start)
		printf("start\n");
	else if (customer.status == end)
		printf("end\n");
	printf("arrivalTime : %d\n", customer.arrivalTime);
	printf("serviceTime : %d\n", customer.serviceTime);
}

void printWaitQueueStatus(SimCustomer customer)
{
	if (customer.status == arrival)
		printf("arrival\n");
	else if (customer.status == start)
		printf("start\n");
	else if (customer.status == end)
		printf("end\n");
	printf("arrivalTime : %d\n", customer.arrivalTime);
	printf("serviceTime : %d\n", customer.serviceTime);
	printf("startTime : %d\n", customer.startTime);
	printf("endTime : %d\n", customer.endTime);
}

void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf("===== waitQueue status =====\n");
	printf("status -> ");
	iterDeque(pWaitQueue, printWaitQueueStatus);
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("totalWaitTime : %d\n", totalWaitTime);
}
