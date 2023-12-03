/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:22:52 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 21:46:40 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_len(t_list *l, char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		l->counter += write(1, "(null)", l->zero);
		return ;
	}
	while (str[i] && i < l->zero)
	{
		l->counter += ft_putchar(str[i]);
		i++;
	}
	l->zero = 0;
}

static void	ft_d(t_list *l, va_list ap2, va_list ap3)
{
	l->zero -= calcule_number(va_arg(ap2, int));
	if (va_arg(ap3, int) < 0)
	{
		l->zero += 1;
		l->counter += ft_putchar('-');
		l->is_minus = 1;
	}
}

void	ft_dot(const char *format, t_list *l, va_list ap2)
{
	va_list	ap3;

	va_copy(ap3, ap2);
	l->index++;
	l->zero = ft_atoi(format + l->index);
	while (ft_isdigit(format[l->index]))
		l->index++;
	if (format[l->index] == 'd' || format[l->index] == 'i')
		ft_d(l, ap2, ap3);
	else if (format[l->index] == 'u')
		l->zero -= calcule_number(va_arg(ap2, t_int));
	else if (format[l->index] == 'x' || format[l->index] == 'X')
		l->zero -= count_hexa(va_arg(ap2, t_int), format[l->index]);
	else if (format[l->index] == 'p')
		l->zero -= count_hexa((t_long) va_arg(ap2, void *), 'm') + 2;
	else if (format[l->index] == 's')
	{
		l->is_dot = 1;
		ft_putstr_len(l, va_arg(l->ap, char *));
	}
	va_end(ap3);
}