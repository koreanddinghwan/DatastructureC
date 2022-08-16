#ifndef _BIN_TREE_
#define _BIN_TREE_

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "linkedstack.h"


#ifndef BTREE_NODE
# define BTREE_NODE

typedef struct t_data
{
	char data;
	int visited;
} Data;

typedef struct BinTreeNodeType
{
	Data 					data;
	struct BinTreeNodeType* pParent;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

#endif

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode *makeNewNodeBT(BinTreeNode element);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTree *root, BinTreeNode* pNode);
void preorderTraversalBinTree(BinTreeNode *pNode, void (*fp)(Data));
void inorderTraversalBinTree(BinTreeNode *pNode, void (*fp)(Data));
void postorderTraversalBinTree(BinTreeNode *pNode, void (*fp)(Data));

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
