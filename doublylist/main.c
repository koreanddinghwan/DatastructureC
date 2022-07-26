#include "doublylist.h"

void test1()
{
	printf("생성 테스트\n");
	DoublyList *dlst = createDoublyList();
	displayDoublyList(dlst);
	deleteDoublyList(dlst);
}

void testielem(DoublyList *dlst, int i)
{
	printf("===========\n");
	printf("test left : %d||", getDLElement(dlst, i)->pLLink->data);
	printf("%d번쨰 값 : %d||", i, getDLElement(dlst, i)->data);
	printf("test right : %d ", getDLElement(dlst, i)->pRLink->data);
	printf("===========\n");
}

void test2()
{
	printf("\n\n===========인자 테스트=========\n");
	DoublyList *dlst = createDoublyList();
	DoublyListNode tmp;
	tmp.data = 1;
	addDLElement(dlst, 1, tmp);
	printf("\n\n아무것도 출력되지 않음.\n");
	displayDoublyList(dlst);

	addDLElement(dlst, -1, tmp);
	printf("\n\n아무것도 출력되지 않음.\n");
	displayDoublyList(dlst);

	addDLElement(dlst, 0, tmp);

	printf("\n\npushback test\n");
	tmp.data = 10;
	addDLElement(dlst, 1, tmp);
	printf("1 -> 10\n");
	printf("header right : %d\n", dlst->headerNode.pRLink->data);
	printf("header left : %d\n", dlst->headerNode.pLLink->data);
	for (int i = 0; i < dlst->currentElementCount; i++)
		testielem(dlst, i);

	printf("\n\npushback test\n");
	tmp.data = 20;
	addDLElement(dlst, 2, tmp);
	printf("1 -> 10 -> 20\n");
	printf("header right : %d\n", dlst->headerNode.pRLink->data);
	printf("header left : %d\n", dlst->headerNode.pLLink->data);
	for (int i = 0; i < dlst->currentElementCount; i++)
		testielem(dlst, i);

	printf("\n\npushback test\n");
	tmp.data = 30;
	addDLElement(dlst, 3, tmp);
	printf("1 -> 10 -> 20 -> 30\n");
	printf("header right : %d\n", dlst->headerNode.pRLink->data);
	printf("header left : %d\n", dlst->headerNode.pLLink->data);
	for (int i = 0; i < dlst->currentElementCount; i++)
		testielem(dlst, i);


	printf("\n\npushback test\n");
	tmp.data = 40;
	addDLElement(dlst, 4, tmp);
	printf("1 -> 10 -> 20 -> 30 -> 40\n");
	printf("header right : %d\n", dlst->headerNode.pRLink->data);
	printf("header left : %d\n", dlst->headerNode.pLLink->data);
	for (int i = 0; i < dlst->currentElementCount; i++)
		testielem(dlst, i);

	printf("값 : %d\n",  getDLElement(dlst, 3)->data);
	deleteDoublyList(dlst);
}

void test3(void)
{
	printf("\n\ninsert test\n");

	DoublyList *dlst = createDoublyList();
	DoublyListNode tmp;
	tmp.data = 1;
	addDLElement(dlst, 0, tmp);
	tmp.data = 10;
	addDLElement(dlst, 1, tmp);
	tmp.data = 20;
	addDLElement(dlst, 2, tmp);
	tmp.data = 30;
	addDLElement(dlst, 3, tmp);
	tmp.data = 40;
	addDLElement(dlst, 4, tmp);
	tmp.data = 15;
	addDLElement(dlst, 2, tmp);
	for (int i = 0; i < getDoublyListLength(dlst); i++)
		testielem(dlst, i);
	tmp.data = 25;
	addDLElement(dlst, 4, tmp);
	for (int i = 0; i < getDoublyListLength(dlst); i++)
		testielem(dlst, i);
	deleteDoublyList(dlst);
}

void test4(void)
{
	printf("\n\ndelete test\n");

	DoublyList *dlst = createDoublyList();
	DoublyListNode tmp;

	tmp.data = 10;

	addDLElement(dlst, 0, tmp);
	tmp.data = 20;
	addDLElement(dlst, 1, tmp);
	tmp.data = 30;
	addDLElement(dlst, 2, tmp);
	removeDLElement(dlst, 1);
	displayDoublyList(dlst);
	deleteDoublyList(dlst);
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	while (1)
		;
	return (0);
}
