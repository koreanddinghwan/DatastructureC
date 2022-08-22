#include "vector.h"
#include <printf.h>

void printvecdata(t_vector *vec)
{
	printf("cap : %d, curcnt : %d, frontvalue : %d, rear : %d\n", vec_maxsize(vec), vec_size(vec), vec_front(vec)->a, vec_back(vec)->a);
}

int main(void)
{
	t_data tmp;
	t_vector *vec = vector(2);

	tmp.a = 1;
	vec_push_back(vec, tmp);
	printvecdata(vec);

	tmp.a = 2;
	vec_push_back(vec, tmp);
	printvecdata(vec);

	tmp.a = 3;
	vec_push_back(vec, tmp);
	printvecdata(vec);

	tmp.a = 4;
	vec_push_back(vec, tmp);
	printvecdata(vec);

	tmp.a = 5;
	vec_push_back(vec, tmp);
	printvecdata(vec);

	tmp.a = 6;
	vec_push_back(vec, tmp);
	printvecdata(vec);

	printf("popback : %d\n", vec_pop_back(vec)->a);
	printvecdata(vec);
	printf("popback : %d\n", vec_pop_back(vec)->a);
	printvecdata(vec);
	printf("popback : %d\n", vec_pop_back(vec)->a);
	printvecdata(vec);
	printf("popback : %d\n", vec_pop_back(vec)->a);
	printvecdata(vec);
	printf("popback : %d\n", vec_pop_back(vec)->a);
	printvecdata(vec);

	printf("popback : %d\n", vec_pop_back(vec)->a);
	printf("%d, %d\n", vec->m_capacity, vec->m_curCnt);
	return (0);
}
