#include "doublylist.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <printf.h>

DoublyList* createDoublyList()
{
	DoublyList *rtn = calloc(1, sizeof(DoublyList));
	if (!rtn)
		exit (ENOMEM);
	rtn->currentElementCount = 0;
	rtn->headerNode.data = 2147483647;
	return (rtn);
}

void deleteDoublyList(DoublyList* pList)
{
	if (!pList)
		exit(EFAULT);
	clearDoublyList(pList);
	free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	if (!pList)
		exit(EFAULT);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	DoublyListNode *new = calloc(1, sizeof(DoublyListNode));
	if (!new)
		exit(ENOMEM);
	//initialize
	memcpy(new, &element, sizeof(DoublyListNode));
	new->pRLink = new;
	new->pLLink = new;

	//except for first elem
	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pRLink = new;
		pList->headerNode.pLLink = new;
		pList->currentElementCount++;
		return (TRUE);
	}

	//pushback
	else if (position == pList->currentElementCount)
	{
		pList->headerNode.pLLink->pRLink = new;
		pList->headerNode.pRLink->pLLink = new;
		new->pLLink = pList->headerNode.pLLink;
		new->pRLink = pList->headerNode.pRLink;
		pList->headerNode.pLLink = new;
		pList->currentElementCount++;
		return (TRUE);
	}

	else
	{
		//insert
		DoublyListNode *positionNode = getDLElement(pList, position);
		DoublyListNode *lNode = getDLElement(pList, position - 1);

		new->pRLink = positionNode;
		positionNode->pLLink = new;
		if (lNode)
		{
			new->pLLink = lNode;
			lNode->pRLink = new;
		}

		//headerNode update
		if (position == 0)
			pList->headerNode.pRLink = new;
		if (position == pList->currentElementCount)
			pList->headerNode.pLLink = new;
		pList->currentElementCount++;
		return (TRUE);
	}
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *del;
	DoublyListNode *lNode;
	DoublyListNode *rNode;

	if (!pList)
		exit(EFAULT);
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	del = getDLElement(pList, position);
	lNode = del->pLLink;
	rNode = del->pRLink;
	lNode->pRLink = rNode;
	rNode->pLLink = lNode;
	if (position == 0)
		pList->headerNode.pRLink = rNode;
	if (position == pList->currentElementCount - 1)
		pList->headerNode.pLLink = lNode;
	free(del);
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	if (!pList)
		exit(EFAULT);
	int j = pList->currentElementCount;
	for (int i = 0; i < j; i++)
		removeDLElement(pList, 0);
	pList->currentElementCount = 0;
}

int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		exit(EFAULT);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	if (!pList)
		exit(EFAULT);
	
	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	if (position == 0)
		return (pList->headerNode.pRLink);
	else if (position == pList->currentElementCount - 1)
		return (pList->headerNode.pLLink);
	DoublyListNode *cur;
	if (position < pList->currentElementCount / 2)
	{
		cur = pList->headerNode.pRLink;
		for (int i = 0; i < position; i++)
			cur  = cur->pRLink;
	}
	else
	{
		cur = pList->headerNode.pLLink;
		position = pList->currentElementCount - position - 1;
		for (int i = 0; i < position; i++)
			cur  = cur->pLLink;
	}
	return (cur);
}

void displayDoublyList(DoublyList* pList)
{
	if (!pList)
		exit(EFAULT);
	printf("|||||노드출력|||||\n");
	DoublyListNode *cur = pList->headerNode.pRLink;
	for (int i = 0; i < pList->currentElementCount * 2; i++)
	{
		if (i < pList->currentElementCount)
			printf("|| [%d번째 데이터] [%d]\n", i, cur->data);
		else
			printf("|| 1회전 [%d번째 데이터] [%d]\n", i - pList->currentElementCount, cur->data);
		cur=cur->pRLink;
	}
	printf("||||||||||||||||\n");
}
