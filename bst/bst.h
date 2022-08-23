#ifndef BST_H
# define BST_H


#ifndef BTREE_NODE
# define BTREE_NODE

#include <math.h>
#include <stdlib.h>

typedef struct t_data
{
	int key;
	int height;
} Data;

typedef struct BinTreeNodeType
{
	Data 					data;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;
#endif

int max(int a, int b);
void bst_insert(BinTreeNode **root, int key);
void bst_delete(BinTreeNode *prev, BinTreeNode **node, int key);
void inorderTraversalBinTree(BinTreeNode *node, void (*fp)(Data));
Data *search(BinTreeNode *root, int key);
BinTreeNode *minNode(BinTreeNode *sbroot);
BinTreeNode *leftRotate(BinTreeNode *x);
BinTreeNode *rightRotate(BinTreeNode *x);
int getBalance(BinTreeNode *node);
#endif
