NAME = pipex

DIR_LIB = libft/
LIB = $(DIR_LIB)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I. #prend les .h dans le dossier courrant ou en deux variable une pour le cemin et une pour le flag

SRCS = pipex.c \
parsing.c \
node.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C $(DIR_LIB)

%.o: %.c
	$(CC) $(CFLAGS)  -o $@ -c $<

clean:
	rm -f $(OBJS)
	make clean -C $(DIR_LIB)

fclean:
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)

re: fclean all

.PHONY: fclean clean all rm