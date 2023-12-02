CFLAGS = -Wall -Wextra -Werror

CC = cc

AR = ar -r

NAME = libftprintf.a
LIBFT = libft/libft.a

FILES = ft_printf.c  ft_putchar.c  ft_putstr.c \
		ft_putnbr.c ft_putnbr_unsigned.c  ft_putnbr_hexa.c \
		ft_atoi.c ft_isdigit.c ft_strlen.c ft_count_number.c \
		ft_itoa.c ft_count_hexa.c ft_find_flags.c

FILES_O = $(FILES:.c=.o)

all : $(NAME) 

$(NAME) : $(FILES_O) 
	$(AR) $(NAME)  $(FILES_O) 

bonus : all

clean : 
	rm -f $(FILES_O)

fclean : clean 
	rm -f $(NAME)

re : fclean all