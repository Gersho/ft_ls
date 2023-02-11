SRCS	= main.c

OBJS		= $(SRCS:.c=.o)
NAME		= ft_ls
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

%.o: 		%.c	ft_ls.h
			$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			gcc $< libft/libft.a -o $(NAME)

clean:
			$(RM) $(OBJS)
			make -C libft/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a

re:			fclean all

.PHONY:		re fclean clean all