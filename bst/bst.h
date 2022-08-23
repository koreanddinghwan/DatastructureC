#ifndef BST_H
# define BST_H


#ifndef BTREE_NODE
# define BTREE_NODE

typedef struct t_data
{
	int key;
} Data;

typedef struct BinTreeNodeType
{
	Data 					data;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;
#endif

void bst_insert(BinTreeNode **root, int key);
void bst_delete(BinTreeNode *prev, BinTreeNode **node, int key);
void inorderTraversalBinTree(BinTreeNode *node, void (*fp)(Data));
Data *search(BinTreeNode *root, int key);
BinTreeNode *minNode(BinTreeNode *sbroot);
#endif
