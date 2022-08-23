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
	deleteLinkedStack(instack);
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
	LinkedStack *instack = createLinkedStack();
	LinkedStack *outstack = createLinkedStack();
	StackNode *poped;
	int parens = 0;

	for (int i = 0; i < tokenCount; i++)
	{
		if (pExprTokens[i].type == operand)//피연산자
			pushLSExprToken(outstack, pExprTokens[i]);
		else if (pExprTokens[i].type == lparen)//(
		{
			pushLSExprToken(instack, pExprTokens[i]);
			parens++;
		}
		else if (pExprTokens[i].type == rparen)//)
		{
			parens++;
			while (peekLS(instack)->data.type != lparen)//instack top이 (까지
			{
				poped = popLS(instack);
				pushLSExprToken(outstack, poped->data);
				free(poped);
			}
			poped = popLS(instack);//( pop
			free(poped);
		}
		else//+, - * /
		{
			if (isLinkedStackEmpty(instack) == TRUE)//instack이 empty
				pushLSExprToken(instack, pExprTokens[i]);
			else
			{
				while (instack->currentElementCount > 0)
				{
					if (inStackPrecedence(peekLS(instack)->data.type) >= inStackPrecedence(pExprTokens[i].type))
					{
						poped = popLS(instack);
						pushLSExprToken(outstack, poped->data);
						free(poped);
					}
					else
						break ;
				}
				pushLSExprToken(instack, pExprTokens[i]);
			}
		}
	}
	while (isLinkedStackEmpty(instack) == FALSE)
	{
		poped = popLS(instack);
		pushLSExprToken(outstack, poped->data);
		free(poped);
	}


	//paste to original pExprTokens
	tokenCount -= parens;
	tokenCount--;
	while (tokenCount >= 0)
	{
		poped = popLS(outstack);
		pExprTokens[tokenCount] = poped->data;
		tokenCount--;
		free(poped);
	}
	deleteLinkedStack(instack);
	deleteLinkedStack(outstack);
}

int inStackPrecedence(Precedence oper)
{
	switch (oper)
	{
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
		case lparen :
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
		printf("%.2f ", element.value);
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

