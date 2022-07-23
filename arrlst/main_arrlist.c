#include "arraylist.h"

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

	printf("\n\n##########################\n");
	//replace
	tmp.data = 2;
	addALElement(pList, 2, tmp);
	displayArrayList(pList);

	///////////////remove test///////////////////
	printf("\n\n##########################\n");
	//delete index 0
	removeALElement(pList, -1);//err
	removeALElement(pList, 0);
	displayArrayList(pList);
	printf("\n\n##########################\n");
	removeALElement(pList, 4);//error
	displayArrayList(pList);
	removeALElement(pList, 3);
	displayArrayList(pList);
	clearArrayList(pList);
	displayArrayList(pList);

	printf("\n\n##########################\n");
	deleteArrayList(pList);
	}
	return 0;
};
