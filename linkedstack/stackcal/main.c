#include  "stackcal.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	int i;
	ExprToken *tokens = splitToken(av[1], &i);
	convertInfixToPostfix(tokens, i);
	calcExpr(tokens, i);
	for (int j = 0; j < i; j++)
		printToken(tokens[j]);
	while (1)
		;
	return 0;
}
