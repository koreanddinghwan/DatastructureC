#include "btree.h"
#include "linkedstack.h"
#include <stdint.h>
BinTreeNode *makeNewNodeBT(BinTreeNode element)
{
	BinTreeNode *rtn;

	rtn = malloc(sizeof(BinTreeNode));
	if (!rtn)
		exit (ENOMEM);
	rtn->data = element.data;
	rtn->pParent = NULL;
	rtn->pLeftChild = NULL;
	rtn->pRightChild = NULL;
	return (rtn);
}

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *root;

	root = malloc(sizeof(BinTree));
	if (!root)
		exit (ENOMEM);
	root->pRootNode = makeNewNodeBT(rootNode);
	return (root);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *child;

	if (!pParentNode)
		return (NULL);
	child = makeNewNodeBT(element);
	{
		pParentNode->pLeftChild = child;
		child->pParent = pParentNode;
	}
	return (child);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *child;

	if (!pParentNode)
		return (NULL);
	child = makeNewNodeBT(element);
	{
		pParentNode->pRightChild = child;
		child->pParent = pParentNode;
	}
	return (child);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{}

/*
 * 삭제하고자 하는 노드를 지우고, 가장 깊은 노드(가장 오른쪽에 있는 노드)로 대체
 * https://www.geeksforgeeks.org/deletion-binary-tree/
 * */

BinTreeNode *getDeepestNode(BinTree *root)
{
	LinkedStack *stack;
	StackNode tmp;
	StackNode *node;
	BinTreeNode *rtn;

	if (!root || !root->pRootNode)
		return (NULL);
	stack = createLinkedStack();
	tmp.data = root->pRootNode;
	pushLS(stack, tmp);
	while (!isLinkedStackEmpty(stack))
	{
		node = popLS(stack);
		if (node->data->pLeftChild)
		{
			tmp.data = node->data->pLeftChild;
			pushLS(stack, tmp);
		}
		if (node->data->pRightChild)
		{
			tmp.data = node->data->pRightChild;
			pushLS(stack, tmp);
		}
		if (!isLinkedStackEmpty(stack))
			free(node);
	}
	rtn = node->data;
	free(node);
	deleteLinkedStack(stack);
	return (rtn);
}

void deleteBinTreeNode(BinTree *root, BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	if (!pNode->pLeftChild && !pNode->pRightChild)
	{//node 0 == leaf
		if (pNode->pParent == NULL)//root
		{
			free(pNode);
			return ;
		}
		//unlink pParent to child
		if ((uintptr_t)pNode->pParent->pLeftChild == (uintptr_t)pNode)
			pNode->pParent->pLeftChild = NULL;
		else
			pNode->pParent->pRightChild = NULL;
		free(pNode);
	}
	else
	{
		BinTreeNode *deepestNode = getDeepestNode(root);

		{//unlink deepestNode
			if ((uintptr_t)deepestNode->pParent->pRightChild == (uintptr_t)deepestNode)
				deepestNode->pParent->pRightChild = NULL;
			else
				deepestNode->pParent->pLeftChild = NULL;
		}

		{
			BinTreeNode *parent = pNode->pParent;
			BinTreeNode *leftChild = pNode->pLeftChild;
			BinTreeNode *rightChild = pNode->pRightChild;


			//parent <-> deepestNode
			if (pNode->pParent == NULL)
			{//pnode is root
				root->pRootNode = deepestNode;
			}
			else
			{
				if ((uintptr_t)parent->pLeftChild == (uintptr_t)pNode)
					parent->pLeftChild = deepestNode;
				else
					parent->pRightChild = deepestNode;
			}
			deepestNode->pParent = parent;

			//leftChild <-> deepestNode
			leftChild->pParent = deepestNode;
			deepestNode->pLeftChild = leftChild;
			rightChild->pParent = deepestNode;
			deepestNode->pRightChild = rightChild;
		}
		free(pNode);
	}
}

void preorderTraversalBinTree(BinTreeNode *pNode, void (*fp)(Data))
{
	if (!pNode)
		return ;
	fp(pNode->data);
	preorderTraversalBinTree(pNode->pLeftChild, fp);
	preorderTraversalBinTree(pNode->pRightChild, fp);
}

void inorderTraversalBinTree(BinTreeNode *pNode, void (*fp)(Data))
{
	if (!pNode)
		return ;
	inorderTraversalBinTree(pNode->pLeftChild, fp);
	fp(pNode->data);
	inorderTraversalBinTree(pNode->pRightChild, fp);
}

void postorderTraversalBinTree(BinTreeNode *pNode, void (*fp)(Data))
{
	if (!pNode)
		return ;
	postorderTraversalBinTree(pNode->pLeftChild, fp);
	postorderTraversalBinTree(pNode->pRightChild, fp);
	fp(pNode->data);
}
