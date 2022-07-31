#include "checkBracketMatching.h"

#include "printf.h"

int checkBracketMatching(char *str)
{
	LinkedStack *brackets;
	StackNode tmp;

	brackets = createLinkedStack();
	while (*str)
	{
		tmp.data = *str;
		switch (*str) {
			case '(' : case '{' : case '[' :
				pushLS(brackets, tmp);
				break ;
			case ')' : case '}' : case  ']' :
				if (isLinkedStackEmpty(brackets) == TRUE)
					return (FALSE);
				else
				{
					StackNode *poped = popLS(brackets);
					if (poped->data == '(')
						poped->data += 1;
					else
						poped->data += 2;
					if (poped->data != *str)
						return (FALSE);
				}
				break ;
		}
		str++;
	}
	if (isLinkedStackEmpty(brackets) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}
