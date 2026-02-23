NAME = pipex

DIR_LIB = libft/
LIB = $(DIR_LIB)libft.a

DIR_PRTF = ft_print/
PRTF = $(DIR_PRTF)libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
INCLUDE = -I. #prend les .h dans le dossier courrant ou en deux variable une pour le cemin et une pour le flag

SRCS = pipex.c \
parsing.c \
pipex_free.c \
pipex_error.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIB) $(PRTF) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(PRTF) -o $(NAME)

$(LIB):
	make -C $(DIR_LIB)

$(PRTF):
	make -C $(DIR_PRTF)

%.o: %.c
	$(CC) $(CFLAGS)  -o $@ -c $<

clean:
	rm -f $(OBJS)
	make clean -C $(DIR_LIB)
	make clean -C $(DIR_PRTF)

fclean:
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)
	make fclean -C $(DIR_PRTF)

re: fclean all

.PHONY: fclean clean all rm