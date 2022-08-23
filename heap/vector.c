#include "vector.h"
#include <sys/errno.h>
#include <printf.h>

t_vector *vector(int capacity)
{
	t_vector *vec = malloc(sizeof(t_vector));
	if (!vec)
		exit (ENOMEM);
	vec->m_elem = malloc(sizeof(t_data) * capacity);
	vec->m_capacity = capacity;
	vec->m_curCnt = 0;
	vec->m_front = 0;
	vec->m_rear = -1;
	return (vec);
}

int vec_size(t_vector *vec)
{
	return (vec->m_curCnt);
}

int vec_maxsize(t_vector *vec)
{
	return (vec->m_capacity);
}


t_data *vec_at(t_vector *vec, int i)
{
	return (vec->m_elem + i);
}

t_data *vec_back(t_vector *vec)
{
	if (vec->m_curCnt <= 0)
		return (NULL);
	return (vec->m_elem + vec->m_rear);
}

t_data *vec_front(t_vector *vec)
{
	if (vec->m_curCnt <= 0)
		return (NULL);
	return (vec->m_elem + vec->m_front);
}

t_data *vec_data(t_vector *vec)
{
	return (vec->m_elem);
}

void vec_clear(t_vector *vec)
{
	free(vec->m_elem);
	free(vec);
}

void vec_resize(t_vector *vec, int s)
{
	t_data *tmp = vec->m_elem;
	vec->m_elem = realloc(vec->m_elem, sizeof(t_data) * s);
	if (!vec->m_elem)
		exit(ENOMEM);
	vec->m_capacity = s;
}

void vec_push_back(t_vector *vec, t_data data)
{
	if (vec->m_capacity == vec->m_curCnt)
		vec_resize(vec, vec->m_capacity * 2);
	vec->m_elem[vec->m_curCnt] = data;
	vec->m_rear++;
	vec->m_curCnt++;
}

t_data *vec_pop_back(t_vector *vec)
{
	if (vec->m_curCnt == 0)
		return (NULL);
	if (vec->m_capacity > vec->m_curCnt * 2)
		vec_resize(vec, vec->m_capacity / 2);
	t_data *rtn = vec->m_elem + vec->m_rear;
	vec->m_rear--;
	vec->m_curCnt--;
	return (rtn);
}

void printvecdata(t_vector *vec)
{
	printf("cap : %d, curcnt : %d, frontvalue : %d, rear : %d\n", vec_maxsize(vec), vec_size(vec), vec_front(vec)->a, vec_back(vec)->a);
}

