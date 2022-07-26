#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdlib.h>
#include <printf.h>
#include <string.h>
#include <errno.h>
#include <printf.h>

#ifndef _LINKEDLIST_NODE
# define _LINKEDLIST_NODE

typedef struct ListNodeType
{
	int weight;
	int vertexID;
	struct ListNodeType* pLink;
} ListNode;

#endif

typedef struct LinkedListType
{
	int currentElementCount;	// ???? ?????? ?????? ????
	ListNode headerNode;		// ???? ????(Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

ListNode *getLLLastElement(LinkedList *pList);
void iteratorLLE(LinkedList *pList, void (*fp)(ListNode));
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
