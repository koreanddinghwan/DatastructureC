NAME = simulation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
DEBUGS = -fsanitize=address

SRCS = linkedstack.c main.c finder.c utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

debug : $(OBJS)
	$(CC) $(CFLAGS) $(DEBUGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) $^ -c -o $@

clean : 
	rm -rf $(OBJS)

fclean :
	make clean;
	rm -rf $(NAME) debug

re : 
	make fclean;
	make all;

.phony : all fclean clean re

