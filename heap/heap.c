#include "heap.h"
#include "vector.h"
#include <stdint.h>
#include <stdlib.h>

void min_heap_push_back(t_vector *vec, t_data data)
{
	int i;

	vec_push_back(vec, data);
	i = vec_size(vec) - 1;
	printf("%d\n", i);
	for (;i != 0 && (vec_data(vec)[(i - 1) / 2].a > vec_data(vec)[i].a); i = (i - 1) / 2)
	{
		swap_data(vec_data(vec) + i, vec_data(vec) + ((i - 1) / 2));
	}
}

t_data heap_get_min(t_vector *vec)
{
	t_data rtn;

	if (vec_size(vec) <= 0)
	{
		rtn.a = INT32_MAX;
		return (rtn);
	}
	if (vec_size(vec) == 1)
	{
		return (*(vec_pop_back(vec)));
	}

	rtn = vec_data(vec)[0];
	vec_data(vec)[0] = *vec_pop_back(vec);
	min_heapify(vec, 0);
	return (rtn);
}

void min_heapify(t_vector *vec, int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int smallest = i;

	if (left < vec_size(vec) && vec_data(vec)[left].a < vec_data(vec)[i].a)
		smallest = left;
	if (right < vec_size(vec) && vec_data(vec)[right].a < vec_data(vec)[smallest].a)
		smallest = right;
	if (smallest != i)
	{
		swap_data(vec_data(vec) + i, vec_data(vec) + smallest);
		min_heapify(vec, smallest);
	}
}

void swap_data(t_data *a, t_data *b)
{
	t_data tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void printvec(t_vector *vec)
{
	printf(ANSI_COLOR_GREEN "======\n" ANSI_COLOR_RESET);
	for (int i =0; i < vec_size(vec); i++)
	{
		printf("vec[%d]: %d\n", i, vec_data(vec)[i].a);
	}
	printf(ANSI_COLOR_GREEN "======\n" ANSI_COLOR_RESET);
}

int main(void)
{
	t_data tmp;
	t_vector *vec = vector(5);

	tmp.a = -1;
	min_heap_push_back(vec, tmp);
	printvec(vec);
	tmp.a = 10;
	min_heap_push_back(vec, tmp);
	printvec(vec);

	tmp.a = 6;
	min_heap_push_back(vec, tmp);
	printvec(vec);
	tmp.a = 2;
	min_heap_push_back(vec, tmp);
	printvec(vec);
	tmp.a = 1;
	min_heap_push_back(vec, tmp);
	printvec(vec);
	tmp.a = -10;
	min_heap_push_back(vec, tmp);
	printvec(vec);

	heap_get_min(vec);
	printvec(vec);

	heap_get_min(vec);
	printvec(vec);
	heap_get_min(vec);
	printvec(vec);
	heap_get_min(vec);
	printvec(vec);
}
