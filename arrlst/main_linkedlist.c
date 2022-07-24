#include "linkedlist.h"

void displayLLElement(LinkedList *pList)
{

}

int main(void)
{
	LinkedList *pList = createLinkedList();

	ListNode tmp;

	tmp.data = 1;
	addLLElement(pList, 0, tmp);


	return 0;
}
