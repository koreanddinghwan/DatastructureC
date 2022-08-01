#include "stackcal.h"
#include "linkedstack.h"

void calcExpr(ExprToken *pExprTokens, int tokenCount)
{
	LinkedStack *instack = createLinkedStack();

	StackNode *n1;
	StackNode *n2;
	ExprToken tmp;
	int i = 0;
	while (i < tokenCount)
	{
		if (pExprTokens[i].type < 6)
		{
			n1 = popLS(instack);
			n2 = popLS(instack);
			tmp.type = operand;

			if (pExprTokens[i].type == times)
				tmp.value = n1->data.value * n2->data.value;
			else if (pExprTokens[i].type == divide)
				tmp.value = n1->data.value / n2->data.value;
			else if (pExprTokens[i].type == plus)
				tmp.value = n1->data.value + n2->data.value;
			else if (pExprTokens[i].type == minus)
				tmp.value = n1->data.value - n2->data.value;

			free(n1);
			free(n2);
			pushLSExprToken(instack, tmp);
		}
		else 
			pushLSExprToken(instack, pExprTokens[i]);
		i++;
	}

	StackNode *result = popLS(instack);
	printf("result is %.2f\n", result->data.value);
	free(result);
}

int pushLSExprToken(LinkedStack* pStack, ExprToken data)
{
	StackNode tmp;

	memcpy(&(tmp.data), &data, sizeof(ExprToken));
	pushLS(pStack, tmp);
	return (TRUE);
}

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount)
{
	ExprToken *cur = calloc(tokenCount, sizeof(ExprToken));
	if (!cur)
		exit(ENOMEM);

	memcpy(cur, pExprTokens, sizeof(ExprToken) * tokenCount);
	int i = 0;
	while (i < tokenCount)
	{
		i++;
	}
}

int inStackPrecedence(Precedence oper)
{
	switch (oper)
	{
		case lparen : 
			return (4);
		case times :
			return (3);
		case divide :
			return (3);
		case plus :
			return (2);
		case minus :
			return (2);
		case rparen :
			return (1);
		default:
			break ;
	}
	return 0;
}

int outStackPrecedence(Precedence oper)
{
	switch (oper)
	{
		case lparen : 
			return (4);
		case rparen :
			return (4);
		case times :
			return (3);
		case divide :
			return (3);
		case plus :
			return (2);
		case minus :
			return (2);
		default:
			break ;
	}
	return 0;
}

void printToken(ExprToken element)
{
	if (element.type == operand)
	{
		printf("%f ", element.value);
		return ;
	}
	else
	{
		switch (element.type) {
			case lparen:
				printf("( ");
				break ;
			case rparen:
				printf(") ");
				break ;
			case times:
				printf("* ");
				break ;
			case divide:
				printf("/ ");
				break ;
			case plus:
				printf("+ ");
				break ;
			case minus:
				printf("- ");
				break ;
			default:
				printf("? ");
				break ;
		}
	}
}

