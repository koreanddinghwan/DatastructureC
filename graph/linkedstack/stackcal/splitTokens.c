#include "stackcal.h"
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

int getSplitedSize(char **splited)
{
	int i = 0;

	while (splited[i])
	{
		i++;
	}
	return (i);
}

ExprToken* splitToken(char *str, int *j)
{
	char **splited;
	ExprToken* tokens;
	int size;
	int i;

	splited = ft_split(str, ' ');
	size = getSplitedSize(splited);
	tokens = calloc(size, sizeof(ExprToken));

	i = 0;
	while (i < size)
	{
		initToken(tokens + i, splited[i]);
		i++;
	}
	*j = i;
	return (tokens);
}
