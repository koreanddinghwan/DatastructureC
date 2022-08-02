#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct MapPositionType
{
	int x;				// ???? 위치 x??표.
	int y;				// ???? 위치 y??표.
	int *direction;		// ??음 위치?? ?絹? ????.
} MapPosition;

typedef struct StackNodeType
{
	MapPosition data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ???? ?????? ????
	StackNode* pTopElement;		// Top ?????? ??????
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
