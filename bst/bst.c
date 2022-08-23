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
	node->data.height = 1;

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

	//insert
	if (prev->data.key > key)
		prev->pLeftChild = node;
	else
		prev->pRightChild = node;
	prev->data.height = max(prev->pLeftChild->data.key, prev->pRightChild->data.key) + 1;


#ifdef AVL
	//balancing

	int balance = getBalance(prev);

	//LL
	if (balance > 1 && key < prev->pLeftChild->data.key)
		(rightRotate(prev));
	//LR
	else if (balance > 1 && key > prev->pLeftChild->data.key)
	{
		prev->pLeftChild = leftRotate(prev->pLeftChild);
		rightRotate(prev);
	}
	//RR
	else if (balance < -1 && key > prev->pRightChild->data.key)
		leftRotate(prev);
	//RL
	else if (balance < -1 && key < prev->pRightChild->data.key)
	{
		prev->pRightChild = rightRotate(prev->pRightChild);
		leftRotate(prev);
	}
#endif
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
			int tmpkey = min->data.key;
			bst_delete(prev, &(*node)->pRightChild, key);
			(*node)->data.key = tmpkey;
		}
	}

#ifdef AVL
	//balancing
	if (!prev)
		return ;
	prev->data.height = max(prev->pLeftChild->data.height, prev->pRightChild->data.key);

	int balance = getBalance(prev);

	//LL
	/*T1, T2, T3 and T4 are subtrees.
			 z(prev)                                y
			/ \                                   /   \
		   y   T4      Right Rotate (z)          x      z
		  / \          - - - - - - - - ->      /  \    /  \ 
		 x   T3                               T1  T2  T3  T4
		/ \
	  T1   T2
	*/
	if (balance > 1 && getBalance(prev->pLeftChild) >= 0)
		rightRotate(prev);
	//LR
	/*
		 z                               z                           x
		/ \                            /   \                        /  \ 
	   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
	  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
	T1   x                          y    T3                    T1  T2 T3  T4
		/ \                        / \
	  T2   T3                    T1   T2
	 * */
	if (balance > 1 && getBalance(prev->pLeftChild) < 0)
	{
		prev->pLeftChild = leftRotate(prev->pLeftChild);
		rightRotate(prev);
	}

	//RR
	/*
	  z                                y
	 /  \                            /   \ 
	T1   y     Left Rotate(z)       z      x
		/  \   - - - - - - - ->    / \    / \
	   T2   x                     T1  T2 T3  T4
		   / \
		 T3  T4
	*/
	if (balance < 0 && getBalance(prev->pRightChild) <= 0)
		leftRotate(prev);

	//RL
/*
   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
 * */
	if (balance < 0 && getBalance(prev->pRightChild) > 0)
	{
		rightRotate(prev->pRightChild);
		leftRotate(prev);
	}
#endif
}

BinTreeNode *minNode(BinTreeNode *sbroot)
{
	while (sbroot && sbroot->pLeftChild)
		sbroot = sbroot->pLeftChild;
	return (sbroot);
}

/*
 *
 *   y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
 * */

BinTreeNode *rightRotate(BinTreeNode *y)
{
	BinTreeNode *x = y->pLeftChild;
	BinTreeNode *T2 = x->pRightChild;

	x->pRightChild = y;
	y->pLeftChild = T2;

	y->data.height = max(y->pLeftChild->data.height, y->pRightChild->data.height) + 1;
	x->data.height = max(x->pLeftChild->data.height, x->pRightChild->data.height) + 1;
	return (x);
}


BinTreeNode *leftRotate(BinTreeNode *x)
{
	BinTreeNode *y = x->pRightChild;
	BinTreeNode *T2 = y->pLeftChild;

	y->pLeftChild = x;
	x->pRightChild = T2;


	x->data.height = max(x->pLeftChild->data.height, x->pRightChild->data.height) + 1;
	y->data.height = max(y->pLeftChild->data.height, y->pRightChild->data.height) + 1;
	return (y);
}

void inorderTraversalBinTree(BinTreeNode *node, void (*fp)(Data));


int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int getBalance(BinTreeNode *node)
{
	if (!node)
		return 0;
	return (node->pLeftChild->data.height - node->pRightChild->data.height);
}
