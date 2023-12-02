/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:53:40 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/02 15:44:48 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_exist(char c)
{
	if (c == '-' || c == '0' || c == '.')
		return (1);
	return (0);
}

int	ft_check_args_bonus(const char *format, t_list *l)
{
	int	i;

	i = 0;
	l->margin = 0;
	if (format[i] == '-')
	{
		i++;
		l->margin = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
		if (format[i] == 'd' || format[i] == 'i')
			l->margin -= calcule_number(va_arg(l->ap2, int));
		else if (format[i] == 'c')
			l->margin -= 1;
		else if (format[i] == 's')
			l->margin -= ft_strlen(va_arg(l->ap2, char *));
		else if (format[i] == 'u')
			l->margin -= calcule_number(va_arg(l->ap2, unsigned int));
		else if (format[i] == 'x' || format[i] == 'X')
			l->margin -= count_hexa(va_arg(l->ap2, unsigned int), format[i]);
		else if (format[i] == 'p')
			l->margin -= count_hexa((unsigned long) va_arg(l->ap2, void *), 'm') + ft_strlen("0x");
	}
	return (i);
}

static int	ft_check_args(const char *str, va_list ap)
{
	int		count;
	int		i;
	char	c;

	i = 0;
	count = 0;
	if (str[i] == 'c')
	{
		c = va_arg(ap, int);
		count += write(1, &c, 1);
	}
	else if (str[i] == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_putnbr_hexa(va_arg(ap, unsigned int), str[i]);
	else if (str[i] == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hexa((unsigned long) va_arg(ap, void *), 'm');
	}
	return (count);
}

int	find_flags(const char *format, t_list *l, va_list ap)
{
	int	i;

	i = 0;
	l->margin = 0;
	l->margin = ft_atoi(format + i);
	if (ft_isdigit(format[i]))
	{
		l->margin -= calcule_number(l->margin);
		i = calcule_number(l->margin);
	}
	if (ft_is_exist(format[i]))
		i += ft_check_args_bonus(format + i, l);
	if (format[i] == '%')
		l->counter += ft_putchar(format[i]);
	else if (!ft_is_exist(format[i]))
		l->counter += ft_check_args(&format[i], ap);
	while (l->margin-- > 0)
		l->counter += ft_putchar(' ');
	l->index += i;
	return (l->margin);
}
