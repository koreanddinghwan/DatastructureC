#include "arraylist.h"
#include <stdlib.h>
#include <string.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *Alst;

	if (maxElementCount <= 0)
		exit(EFAULT);

	Alst = malloc(sizeof(ArrayList) * 1);
	if (!Alst)
		exit(ENOMEM);

	Alst->pElement = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!Alst->pElement)
	{
		free(Alst);
		exit(ENOMEM);
	}

	Alst->maxElementCount = maxElementCount;
	Alst->currentElementCount = 0;
	return (Alst);
}

void deleteArrayList(ArrayList* pList)
{
	if (!pList)
		exit(EFAULT);
	if (pList->pElement)
		free(pList->pElement);
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		exit(EFAULT);
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

//java ArrayList.add 참고.
//https://www.tutorialspoint.com/java/util/arraylist_add_index.htm
//C에선 메서드오버로딩을 지원하지 않으므로, position 을 flag삼아야함
//배열꽉차면 realloc, size+1;
//만약 position == -1 => pushback

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (!pList)
		exit(EFAULT);
	if (position < -1 || position >= pList->maxElementCount)
	{
		printf("index out of range\n");
		return (FALSE);
	}
	if (position != -1 && (position > pList->currentElementCount))
	{
		printf("add index is too large\n");
		return (FALSE);
	}

	if (isArrayListFull(pList) == TRUE)
	{
		//realloc?
		printf("reallocation memory...\n");
		ArrayListNode *tmp = pList->pElement;
		pList->pElement = realloc(pList->pElement,  sizeof(ArrayListNode) * (pList->maxElementCount * 2));
		if (!pList->pElement)
		{
			free(tmp);
			exit(ENOMEM);
		}
		pList->maxElementCount *= 2;
	}

	if (position == -1)
	{
		//pushback
		memcpy(pList->pElement + pList->currentElementCount++, &element, sizeof(ArrayListNode));
		return (TRUE);
	}

	//insert
	memmove(pList->pElement + position + 1, pList->pElement + position, sizeof(ArrayListNode) * (pList->currentElementCount - (position)));
	memcpy(pList->pElement + position, &element, sizeof(ArrayListNode));
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	if (!pList)
		exit(EFAULT);
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("removing index out of range\n");
		return (FALSE);
	}
	for (int i = position; i < pList->currentElementCount - 1; i++)
		memmove(pList->pElement + i, pList->pElement + i + 1, sizeof(ArrayListNode));
	pList->currentElementCount--;
/////////////////////////
	if (pList->currentElementCount < pList->maxElementCount / 2)
	{
		printf("reacllocation size down\n");
		ArrayListNode *tmp = pList->pElement;
		pList->pElement = realloc(pList->pElement, sizeof(ArrayListNode) * (pList->maxElementCount / 2));
		if (!pList->pElement)
		{
			free(tmp);
			exit(ENOMEM);
		}
		pList->maxElementCount = pList->maxElementCount / 2;
	}
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (!pList)
		exit(EFAULT);
	if (position >= pList->currentElementCount || position < 0)
	{
		printf("get index out of range\n");
		return (NULL);
	}
	return (pList->pElement + position);
}

void displayArrayList(ArrayList* pList)
{
	if (!pList)
		exit(EFAULT);
	if (getArrayListLength(pList) == 0)
		printf("--0 element--\n");
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pListp[%d] : %d\n", i, (pList->pElement + i)->data);
}

void clearArrayList(ArrayList* pList)
{
	if (!pList)
		exit(EFAULT);
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	if (!pList)
		exit(EFAULT);;
	return (pList->currentElementCount);
}
