#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <printf.h>

typedef struct DoublyListNodeType
{
	int data;
	float coef;
	int degree;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
	void *content;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// ???? ?????? ?????? ????
	DoublyListNode	headerNode;		// ???? ????(Header Node)
} DoublyList;

DoublyList* createDoublyList();
void deleteDoublyList(DoublyList* pList);
int addDLElement(DoublyList* pList, int position, DoublyListNode element);
int removeDLElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDLElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);

DoublyListNode *newDleNode(void *content);
void iteratorDle(DoublyList* pList, void (*f)(void *));

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
