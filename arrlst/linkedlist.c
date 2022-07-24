#include "linkedlist.h"
#include <malloc/_malloc.h>

//https://www.w3schools.com/java/java_linkedlist.asp

LinkedList* createLinkedList(void)
{
	LinkedList *tmp;

	tmp = malloc(sizeof(LinkedList) * 1);
	if (!tmp)
		exit(ENOMEM);
	tmp->currentElementCount = 0;
	tmp->headerNode.pLink = NULL;
	tmp->headerNode.data = 0;
	return (tmp);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	if (!pList)
		exit(EFAULT);
	if ((position != -1 && (position > pList->currentElementCount)) || position < -1)
	{
		printf("add index is Error\n");
		return (FALSE);
	}

	ListNode *new = malloc(sizeof(ListNode) * 1);
	memcpy(new, &element, sizeof(ListNode));
	if (!new)
		exit(ENOMEM);
	new->pLink = NULL;
	if (position == -1 || position == pList->currentElementCount)
	{
		//pushback
		ListNode *last = getLLLastElement(pList);
		last->pLink = new;
	}
	else
	{
		//insert 
		ListNode *back = getLLElement(pList, position - 1);
		ListNode *next = getLLElement(pList, position);
		if (back)
			back->pLink = new;
		else if (!back)
			pList->headerNode.pLink = new;
		new->pLink = next;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);

	ListNode *back = getLLElement(pList, position - 1);
	ListNode *cur = getLLElement(pList, position);
	ListNode *next = getLLElement(pList, position + 1);
	if (back)
		back->pLink = next;
	else
		pList->headerNode.pLink = next;
	free(cur);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	if (position >= pList->currentElementCount)
		return (NULL);
	if (position <= -1)
		return (NULL);
	ListNode *cur;

	cur = pList->headerNode.pLink;
	for (int i = 0; i < position; i++)
		cur = cur->pLink;
	return (cur);
}

void clearLinkedList(LinkedList* pList)
{
	if (!pList)
		exit(EFAULT);

	for (int i = 0; i < pList->currentElementCount; i++)
		removeLLElement(pList, i);
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
}

int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		exit(EFAULT);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if (!pList)
		exit(EFAULT);
	clearLinkedList(pList);
	free(pList);
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
