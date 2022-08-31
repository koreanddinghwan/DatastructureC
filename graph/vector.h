#ifndef VECTOR_H
# define VECTOR_H

#include <stdlib.h>
#include <errno.h>
#include <printf.h>

typedef struct s_data
{
	int fromVertex;
	int toVertex;
	int weight;
} t_data;

typedef struct s_vector
{
	//member
	t_data *m_elem;
	int m_capacity;
	int m_curCnt;
	int m_front;
	int m_rear;
} t_vector;

t_vector *vector(int capacity);

int vec_size(t_vector *vec);
int vec_maxsize(t_vector *vec);
t_data *vec_at(t_vector *vec, int i);
t_data *vec_back(t_vector *vec);
t_data *vec_front(t_vector *vec);
t_data *vec_data(t_vector *vec);

//modifier
void vec_clear(t_vector *vec);
void vec_resize(t_vector *vec, int s);
void vec_push_back(t_vector *vec, t_data data);
t_data *vec_pop_back(t_vector *vec);


void printvecdata(t_vector *vec);

#endif
