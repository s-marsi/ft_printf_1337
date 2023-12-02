CFLAGS = -Wall -Wextra -Werror

CC = cc

AR = ar -r

NAME = libftprintf.a
LIBFT = libft/libft.a

FILES = ft_printf.c  ft_putchar.c  ft_putstr.c \
		ft_putnbr.c ft_putnbr_unsigned.c  ft_putnbr_hexa.c ft_margin.c

FILES_O = $(FILES:.c=.o)
XX=libft/*.o

all :$(LIBFT) $(NAME) 
$(LIBFT):
	make all  -C ./libft
$(NAME) : $(FILES_O) 
	$(AR) $(NAME) $(XX)  $(FILES_O) 

clean : 
	rm -f $(FILES_O)
	make clean -C ./libft

fclean : clean 
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all 
