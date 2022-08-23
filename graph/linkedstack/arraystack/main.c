#include "arraystack.h"
#include "printf.h"

void printstack(ArrayStack *stack)
{
	int i = stack->currentElementCount - 1;

	while (i >= 0)
	{
		printf("[%c]\n", stack->pTopElement[i].data);
		i--;
	}
}

void test1(void)
{
	ArrayStack *stack = createArrayStack(5);

	StackElement tmp;
	tmp.data = 'a';
	pushAS(stack, tmp);
	tmp.data = 'b';
	pushAS(stack, tmp);
	tmp.data = 'c';
	pushAS(stack, tmp);
	tmp.data = 'd';
	pushAS(stack, tmp);
	tmp.data = 'e';
	pushAS(stack, tmp);
	tmp.data = 'f';
	pushAS(stack, tmp);
	printstack(stack);

	printf("pop : %c\n", popAS(stack)->data);
	printstack(stack);
	printf("pop : %c\n", popAS(stack)->data);
	printstack(stack);
	printf("pop : %c\n", popAS(stack)->data);
	printstack(stack);
	printf("pop : %c\n", popAS(stack)->data);
	printstack(stack);
	printf("pop : %c\n", popAS(stack)->data);
	printstack(stack);
	//printf("pop : %c\n", popAS(stack)->data);
	//printstack(stack);
	deleteArrayStack(stack);
}


int main(void)
{
	test1();
	printf("\n\n");
	return 0;
}
