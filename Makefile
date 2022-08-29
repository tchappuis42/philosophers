
NAME	= philo

SRCS	= philosophers.c philo_utils.c init_philo.c time.c chek_args.c routine.c

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror #/Users/tchappui/sgoinfre/lgyger/.brew/Cellar/llvm/13.0.1_1/bin/clang -g3 -fsanitize=leak

all:		${NAME}

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:		
			${RM} *.o

fclean:		clean
			${RM} ${NAME}

re:			fclean all
