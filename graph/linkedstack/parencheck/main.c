#include "checkBracketMatching.h"
#include "printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	if (checkBracketMatching(av[1]) == TRUE)
		printf("bracket matches\n");
	else 
		printf("Not matches\n");
	return 0;
}
