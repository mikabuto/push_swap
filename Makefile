NAME = 	push_swap

SRCS =	actions2.c errors.c find_best_root.c ft_split.c \
		main.c stack_sort.c stack_utils.c actions.c \
		array_utils.c execute_rotations.c ft_atoi.c \
		ft_strjoin.c stack_sort2.c final_sorting.c

HEAD =	push_swap.h

OBJS = 	$(SRCS:.c=.o)


CC = 	cc
FLAGS = -Wall -Wextra -Werror
RM = 	rm -f

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

.c.o: $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re