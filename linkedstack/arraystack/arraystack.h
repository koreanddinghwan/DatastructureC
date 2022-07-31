#ifndef _ARRAY_STACK_
# define _ARRAY_STACK_

#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct StackElementType
{
	char data;
} StackElement;

typedef struct ArrayStackType
{
	int maxElementCount;
	int currentElementCount;	// ???? ?????? ????
	StackElement* pTopElement;		// Top ?????? ??????
} ArrayStack;

ArrayStack* createArrayStack(unsigned int n);
int pushLS(ArrayStack* pStack, StackElement element);
StackElement* popLS(ArrayStack* pStack);
StackElement* peekLS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
