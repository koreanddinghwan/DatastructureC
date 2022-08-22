#include "heap.h"
#include "vector.h"

void heap_push_back(t_vector *vec, t_data data)
{

}

void make_heap(t_vector *vec)
{
	for (int i = 0; i < vec->m_curCnt; i++)
		heapify_down(vec, i);//i : parent index
}

void heapify_down(t_vector *vec, int i)
{
	int parentIndex = i;
	int leftChildIndex = (i + 1) * 2 - 1;
	int rightChildIndex = (i + 1) * 2 + 1 - 1;

	t_data *parent;
	t_data *leftChild;
	t_data *rightChild;

	parent = vec->m_elem + i;

	if (leftChildIndex >= vec->m_curCnt)
		leftChild = NULL;
	else
		leftChild = vec->m_elem + leftChildIndex;

	if (rightChildIndex >= vec->m_curCnt)
		rightChild = NULL;
	else
		rightChild = vec->m_elem + rightChildIndex;

	//leaf
	if (!leftChild && !rightChild)
		return ;
	else if (!leftChild)
	{
		if (parent->a < rightChild->a)
		{
			swap_data(parent, rightChild);
			heapify_down(vec, rightChildIndex);
		}
	}
	else if (!rightChild)
	{
		if (parent->a < leftChild->a)
		{
			swap_data(parent, leftChild);
			heapify_down(vec, leftChildIndex);
		}
	}//탈출!!
	else if (parent->a >= leftChild->a && parent->a >= rightChild->a)
	{
		return ;
	}
	else
	{
		t_data *max;
		if (leftChild->a > rightChild->a)
		{
			max = leftChild;
			if (max->a > parent->a)
			{
				swap_data(parent, max);
				heapify_down(vec, leftChildIndex);
			}
		}
		else
		{
			max = rightChild;
			if (max->a > parent->a)
			{
				swap_data(parent, max);
				heapify_down(vec, rightChildIndex);
			}
		}
	}
}

void swap_data(t_data *a, t_data *b)
{
	t_data tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void heapify_up(t_vector *vec, int i)
{
	int curIdx = i;
	int siblingIdx;
	if (curIdx % 2 == 0)
		siblingIdx = i - 1;
	else
		siblingIdx = i + 1;
	int parentIdx = i / 2;

	if (curIdx <= 0)
		return ;

	t_data *parent;
	t_data *curChild;
	t_data *siblingChild;

	parent = vec->m_elem + parentIdx;
	
	if (curIdx >= vec->m_curCnt)
		curChild = NULL;
	else
		curChild = vec->m_elem + curIdx;

	if (siblingIdx >= vec->m_curCnt)
		siblingChild = NULL;
	else
		siblingChild = vec->m_elem + siblingIdx;

}
