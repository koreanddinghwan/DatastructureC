#include  "stackcal.h"
#include <stdlib.h>

void initToken(ExprToken *token, char *str)
{
	if (!isnumber(*str))
	{
		switch (*str) {
			case '(' :
				token->type = lparen;
				break ;
			case ')' :
				token->type = rparen;
				break ;
			case '*' :
				token->type = times;
				break ;
			case '/' :
				token->type = divide;
				break ;
			case '-' :
				token->type = minus;
				break ;
			case '+' :
				token->type = plus;
				break ;
		}
	}
	else
	{
		token->type = operand;
		token->value = strtod(str, NULL);
	}
}

int main(int ac, char **av)
{
	if (ac <= 1)
		return 0;
	ExprToken *tokens = calloc(sizeof(ExprToken) , ac);
	int i = 0;
	av++;
	while (*av)
	{
		initToken(tokens + i, *av);
		av++;
		i++;
	}

	//infix to postfix
	//convertInfixToPostfix(tokens, i);
	calcExpr(tokens, i);

	i = 0;
	while (i < ac - 1)
		printToken(tokens[i++]);
	return 0;
}
