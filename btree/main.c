#include <stdarg.h>
#include "btree.h"
#include <printf.h>
void print(Data data)
{
	printf("\n");
	for (int i = 0 ; i < 10; i++)
		printf(" ");
	printf("%c\n", data.data);
}

int main(void)
{
	BinTree *root;
	BinTreeNode node;

	node.data.data = 'A';
	root = makeBinTree(node); 
	inorderTraversalBinTree(root->pRootNode, print);

	printf("======================\n");
	node.data.data = 'B';

	return 0;
}
