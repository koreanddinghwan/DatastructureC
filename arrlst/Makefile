CC=cc
CFLAGS=-Wall -Wextra -Werror -g3 
ARR=arr_test
LLST=lst_test

ARR_SRCS = main_arrlist.c arraylist.c
ARR_OBJS = $(ARR_SRCS:.c=.o)

LLST_SRCS = main_linkedlist.c linkedlist.c
LLST_OBJS = $(LLST_SRCS:.c=.o)


all : $(ARR) $(LLST)

%.o : %.c
	$(CC) $(CFLAGS) $^ -c

$(ARR) : $(ARR_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(LLST) : $(LLST_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean : 
	rm -rf $(ARR_OBJS) $(LLST_OBJS)

fclean :
	make clean;
	rm -rf $(ARR) $(LLST)

re :
	make fclean
	make all
