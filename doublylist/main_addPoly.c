#include "addPoly.h"
#include <stdlib.h>
#include <time.h>


int main(void)
{
	DoublyList *a;
	DoublyList *b;

	a = createDoublyList();
	b = createDoublyList();

	srand(time(NULL));

	int i =0;
	while (i < 10)
	{
		addPolyNodeLast(a, (float)rand()/(float)(RAND_MAX) * 10, 10 - i);
		i++;
	}

	i = 0;
	while (i < 5)
	{
		addPolyNodeLast(b, (float)rand()/(float)(RAND_MAX) * 10, (10 - i));
		i++;
	}

	DoublyList *rtn = addPoly(a, b);
	

	printf("=========a========\n");

	PolyPrint(a);



	printf("\n\n=========b========\n");
	PolyPrint(b);



	printf("\n\n=========rtn========\n");

	PolyPrint(rtn);
	deleteDoublyList(a);
	deleteDoublyList(b);
	deleteDoublyList(rtn);

	return 0;
}
