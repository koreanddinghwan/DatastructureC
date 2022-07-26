#include "linkedlist.h"
#include <stdio.h>

void displayLLElement(LinkedList *pList)
{
	ListNode *cur = pList->headerNode.pLink;
	int i = 0;

	printf("cur_elem num : %d \n", pList->currentElementCount);
	while (cur)
	{
		printf("list[%d] = %d\n", i, cur->data);
		cur = cur->pLink;
		i++;
	}
}

ListNode *getLLLastElement(LinkedList *pList)
{
	if (!pList)
		exit(EFAULT);
	ListNode *cur = pList->headerNode.pLink;
	if (!cur)
		return (&(pList->headerNode));
	while (cur->pLink)
	{
		cur = cur->pLink;
	}
	return (cur);
}

int main(void)
{
	{
	LinkedList *pList = createLinkedList();

	ListNode tmp;

	tmp.data = 1;
	printf("add tmp\n");
	addLLElement(pList, 0, tmp);
	displayLLElement(pList);
	removeLLElement(pList, -2);
	removeLLElement(pList, -1);
	removeLLElement(pList, 1);
	removeLLElement(pList, 0);
	displayLLElement(pList);
	printf("\n\n\n");


	tmp.data = 2;
	addLLElement(pList, -1, tmp);
	displayLLElement(pList);

	tmp.data = 3;
	addLLElement(pList, -1, tmp);
	displayLLElement(pList);

	tmp.data = 4;
		addLLElement(pList, -1, tmp);
	displayLLElement(pList);

	tmp.data = 5;
	addLLElement(pList, 0, tmp);
	displayLLElement(pList);

	tmp.data = 6;
	addLLElement(pList, 3, tmp);
	displayLLElement(pList);


	deleteLinkedList(pList);
	}
	while (1)
		;
	return 0;
}
