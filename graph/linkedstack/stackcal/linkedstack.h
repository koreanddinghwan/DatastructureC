#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef EXPRTOK
# define EXPRTOK

typedef enum PrecedenceType
{
	lparen,
	rparen,
	times,
	divide,
	plus,
	minus,
	operand
} Precedence;

typedef struct ExprTokenType
{
	float value;
	Precedence type;
} ExprToken;
#endif

typedef struct StackNodeType
{
	ExprToken data;
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
