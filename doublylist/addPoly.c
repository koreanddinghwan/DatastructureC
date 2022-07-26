#include "addPoly.h"
#include "doublylist.h"

DoublyList *addPoly(DoublyList *a, DoublyList *b)
{
	DoublyList *rtn;
	DoublyListNode *aCur;
	DoublyListNode *bCur;
	int alength;
	int blength;

	rtn = createDoublyList();
	aCur = a->headerNode.pRLink;
	bCur = b->headerNode.pRLink;
	alength = a->currentElementCount;
	blength = b->currentElementCount;
	while (alength && blength)
	{
		if (aCur->degree > bCur->degree)
		{
			addPolyNodeLast(rtn, aCur->coef, aCur->degree);
			aCur = aCur->pRLink;
			alength--;
		}
		else if (bCur->degree > aCur->degree)
		{
			addPolyNodeLast(rtn, bCur->coef, bCur->degree);
			bCur = bCur->pRLink;
			blength--;
		}
		else
		{
			addPolyNodeLast(rtn, aCur->coef + bCur->coef, aCur->degree + bCur->degree);
			aCur = aCur->pRLink;
			bCur = bCur->pRLink;
			alength--;
			blength--;
		}
	}
	//남은 노드 처리
	while (alength)
	{
		addPolyNodeLast(rtn, aCur->coef, aCur->degree);
		aCur = aCur->pRLink;
		alength--;
	}
	while (blength)
	{
		addPolyNodeLast(rtn, bCur->coef, bCur->degree);
		bCur = bCur->pRLink;
		blength--;
	}
	return (rtn);
}

int addPolyNodeLast(DoublyList *pList, float coef, int degree)
{
	int ret = FALSE;
	int i = 0;

	if (!pList)
		exit(EFAULT);
	DoublyListNode node;
	node.coef = coef;
	node.degree = degree;
	ret = addDLElement(pList, getDoublyListLength(pList), node);
	return (ret);
}

void PolyPrint(DoublyList *pList)
{
	DoublyListNode *cur;
	int i;
	int j;

	cur = pList->headerNode.pRLink;
	i = 0;
	j = pList->currentElementCount;
	while (i < j)
	{
		printf("[%d]번째 데이터 : [계수]=%f [차수]=%d\n", i, cur->coef, cur->degree);
		i++;
		cur = cur->pRLink;
	}
}
