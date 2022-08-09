#ifndef BANKSERVICE_H
# define BANKSERVICE_H

#include "linkeddeque.h"
#include <printf.h>

#ifndef SIM
# define SIM
typedef enum SimStatusType
{
	arrival,
	start,
	end,
} SimStatus;
typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
} SimCustomer;
#endif

# define MAXTIME 13

void insertCustomer(int arrivalTime, int serviceTime, LinkedDeque *pqueue);
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);
DequeNode *processServiceNodeStart(int curTime, LinkedDeque *pWaitQueue);
DequeNode *processServiceNodeEnd(int curTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(SimCustomer customer);
void printWaitQueueStatus(SimCustomer customer);
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif
