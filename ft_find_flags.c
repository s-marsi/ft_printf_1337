/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:53:40 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 21:53:58 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_exist(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "-.0# +";
	while (i < 6)
		if (c == flags[i++])
			return (1);
	return (0);
}

static void	print_d(t_list *l)
{
	va_list	ap2;

	va_copy(ap2, l->ap);
	if (l->is_minus && va_arg(ap2, int) < 0)
	{
		l->counter += ft_putnbr_unsigned(va_arg(l->ap, int) * -1);
		l->is_minus = 0;
	}
	else
		l->counter += ft_putnbr(va_arg(l->ap, int));
}

static void	ft_check_args_bonus(const char *format, t_list *l)
{	
	va_list			ap2;

	va_copy(ap2, l->ap);
	if (format[l->index] == '-')
		ft_minus(format, l, ap2);
	else if (format[l->index] == '0')
		ft_zero(format, l, ap2);
	else if (format[l->index] == '.')
		ft_dot(format, l, ap2);
	else if (format[l->index] == '#')
		ft_sharp(format, l, ap2);
	else if (format[l->index] == ' ')
		ft_space(format, l, ap2);
	else if (format[l->index] == '+')
		ft_plus(format, l, ap2);
	va_end(ap2);
}

static void	ft_check_args(const char *str, t_list *l)
{
	unsigned long	nb;
	int				i;	

	i = l->index;
	if (str[i] == 'c')
		l->counter += ft_putchar(va_arg(l->ap, int));
	else if (str[i] == 's' && !l->is_dot)
		l->counter += ft_putstr(va_arg(l->ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		print_d(l);
	else if (str[i] == 'u')
		l->counter += ft_putnbr_unsigned(va_arg(l->ap, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		l->counter += ft_putnbr_hexa(va_arg(l->ap, unsigned int), str[i]);
	else if (str[i] == 'p')
	{
		l->counter += ft_putstr("0x");
		nb = (unsigned long) va_arg(l->ap, void *);
		l->counter += ft_putnbr_hexa(nb, 'm');
	}
}

void	find_flags(const char *src, t_list *l)
{
	va_list	ap2;

	va_copy(ap2, l->ap);
	l->margin = 0;
	l->zero = 0;
	if (ft_is_exist(src[l->index]))
	{
		ft_check_args_bonus(src, l);
		while (l->zero-- > 0)
			l->counter += ft_putchar('0');
	}
	if (src[l->index] == '%')
		l->counter += ft_putchar(src[l->index]);
	else if (!ft_is_exist(src[l->index]))
		ft_check_args(src, l);
	while (l->margin-- > 0)
		l->counter += ft_putchar(' ');
	va_end(ap2);
}
