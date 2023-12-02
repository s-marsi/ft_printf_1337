/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:12:36 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/02 12:41:25 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_count(const char *format, va_list ap)
{
	t_list	l;

	va_copy(l.ap2, ap);
	l.index = 0;
	l.counter = 0;
	while (format[l.index])
	{
		if (format[l.index] == '%')
		{
			l.index++;
			find_flags(format + l.index, &l, ap);
			l.index++;
		}
		else
		{
			l.counter += ft_putchar(format[l.index]);
			l.index++;
		}
	}
	va_end(l.ap2);
	return (l.counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	va_start(ap, format);
	counter = ft_printf_count(format, ap);
	va_end(ap);
	return (counter);
}
