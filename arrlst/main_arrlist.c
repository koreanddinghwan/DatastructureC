#include "arraylist.h"
#include <stdio.h>

int main(void)
{
	{
	ArrayList *pList = createArrayList(5);

	ArrayListNode tmp;
	tmp.data = 5;
	addALElement(pList, -1, tmp);
	tmp.data = 10;
	addALElement(pList, -1, tmp);
	addALElement(pList, -1, tmp);
	addALElement(pList, -1, tmp);
	addALElement(pList, -1, tmp);
	addALElement(pList, -1, tmp);
	displayArrayList(pList);

	printf("\n\n##########################\n");
	//insert
	tmp.data = 1;
	addALElement(pList, 0, tmp);
	displayArrayList(pList);
	addALElement(pList, -1, tmp);
	displayArrayList(pList);
	printf("\n\n##########################\n");
	tmp.data = 2;
	addALElement(pList, 2, tmp);
	displayArrayList(pList);

	///////////////remove test///////////////////
	printf("\n\n##########################\n");
	//delete index 0
	removeALElement(pList, 3);//err
	removeALElement(pList, 0);
	displayArrayList(pList);


	printf("\n\n##########################\n");
	removeALElement(pList, 4);//error
	displayArrayList(pList);


	printf("\n\n##########################\n");
	removeALElement(pList, 3);
	removeALElement(pList, 3);
	printf("max length : %d, cur length : %d\n", getArrayListMaxLength(pList), getArrayListLength(pList));
	removeALElement(pList, 0);
	displayArrayList(pList);
	printf("max length : %d, cur length : %d\n", getArrayListMaxLength(pList), getArrayListLength(pList));


	printf("\n\n##########################\n");
	removeALElement(pList, 0);
	displayArrayList(pList);
	printf("max length : %d, cur length : %d\n", getArrayListMaxLength(pList), getArrayListLength(pList));


	printf("\n\n##########################\n");
	removeALElement(pList, 0);
	displayArrayList(pList);
	printf("max length : %d, cur length : %d\n", getArrayListMaxLength(pList), getArrayListLength(pList));

	printf("\n\nafter clear\n");
	clearArrayList(pList);
	displayArrayList(pList);

	printf("\n\n##########################\n");
	displayArrayList(pList);
	addALElement(pList, 0, tmp);
	displayArrayList(pList);
	printf("cur size: %d\n", getArrayListLength(pList));
	printf("[0]: %d\n", getALElement(pList, 0)->data);
	removeALElement(pList, 0);
	printf("is full?: %d\n", isArrayListFull(pList));
	printf("max length : %d\n", getArrayListMaxLength(pList));
	}
	return 0;
};
