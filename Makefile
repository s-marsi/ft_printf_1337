CFLAGS = -Wall -Wextra -Werror

CC = cc

AR = ar -r

NAME = libftprintf.a

FILES = ft_printf.c  ft_putchar.c  ft_putstr.c \
		ft_putnbr.c ft_putnbr_unsigned.c  ft_putnbr_hexa.c

FILES_O = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(FILES_O) 
	$(AR) $(NAME) $?

clean : 
	rm -f $(FILES_O) 

fclean : clean 
	rm -f $(NAME)

re : fclean all 
