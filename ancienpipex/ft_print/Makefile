NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c \
	ft_putadrs.c \
	ft_putchar.c \
	ft_puthexa.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_putstr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all rm