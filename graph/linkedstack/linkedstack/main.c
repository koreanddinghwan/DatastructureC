#include "linkedstack.h"
#include "printf.h"

void printstack(LinkedStack *stack)
{
	StackNode *cur = stack->pTopElement;
	while (cur)
	{
		printf("[%c]\n", cur->data);
		cur = cur->pLink;
	}
	printf("---\n");
}

void test1(void)
{
	LinkedStack *stack = createLinkedStack();


	StackNode tmp;

	tmp.data = 'c';
	pushLS(stack, tmp);
	tmp.data = 'd';
	pushLS(stack, tmp);
	printstack(stack);
	StackNode *poped = popLS(stack);
	printf("pop : %c\n", poped->data);
	free(poped);
	printstack(stack);
	deleteLinkedStack(stack);
}

void test2(void)
{
	LinkedStack *stack = createLinkedStack();

	StackNode tmp;

	tmp.data = 'c';
	pushLS(stack, tmp);
	tmp.data = 'd';
	pushLS(stack, tmp);
	printf("peak stack : %c\n", peekLS(stack)->data);
	printstack(stack);
	deleteLinkedStack(stack);
}

int main(void)
{
	test1();
	printf("\n\n");
	test2();
	printf("\n\n");
	while (1)
		;
	return 0;
}
