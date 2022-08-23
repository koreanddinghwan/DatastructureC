#include "bst.h"
#include <stdlib.h>

void bst_insert(BinTreeNode **root, int key)
{
	BinTreeNode *node = malloc(sizeof(BinTreeNode));
	if (!node)
		return ;
	node->data.key = key;
	node->pRightChild = NULL;
	node->pLeftChild = NULL;

	if (!*root)
	{
		*root = node;
		return ;
	}

	BinTreeNode *tmp = *root;
	BinTreeNode *prev = NULL;

	while (tmp)//from root
	{
		if (tmp->data.key > key)//this node goes to left
		{
			prev = tmp;
			tmp = tmp->pLeftChild;
		}
		else if (tmp->data.key < key)//this node goes to right
		{
			prev = tmp;
			tmp = tmp->pRightChild;
		}
	}
	if (prev->data.key > key)
		prev->pLeftChild = node;
	else
		prev->pRightChild = node;

	//balancing
}

void bst_delete(BinTreeNode *prev, BinTreeNode **node, int key)
{
	if (!*node)
		return ;

	if ((*node)->data.key > key)
		bst_delete(*node, &(*node)->pLeftChild, key);
	else if ((*node)->data.key < key)
		bst_delete(*node, &(*node)->pRightChild, key);

	//recursive end with (*node)->data.key == key 
	else
	{
		if (!prev)//root
		{
			free(*node);
			return;
		}
		//case 1 no left and leaf
		if ((*node)->pLeftChild == NULL)
		{
			if (prev->pRightChild == (*node))
				prev->pRightChild = (*node)->pRightChild;
			else
				prev->pLeftChild = (*node)->pRightChild;
			free(*node);
		}
		//case 2 no right
		else if ((*node)->pRightChild == NULL)
		{
			if (prev->pRightChild == (*node))
				prev->pRightChild = (*node)->pLeftChild;
			else
				prev->pLeftChild = (*node)->pLeftChild;
			free(*node);
		}
		//case 3 two children
		else
		{
			//find min node from right subtree and copy key, and delete it;
			BinTreeNode *min = minNode((*node)->pRightChild);
			(*node)->data.key = min->data.key;

			
		}

	}
}

Data *search(BinTreeNode *root, int key)
{

}

BinTreeNode *minNode(BinTreeNode *sbroot)
{
	while (sbroot && sbroot->pLeftChild)
		sbroot = sbroot->pLeftChild;
	return (sbroot);
}

void inorderTraversalBinTree(BinTreeNode *node, void (*fp)(Data));
