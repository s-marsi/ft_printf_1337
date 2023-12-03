/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:11:18 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 19:44:47 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero(const char *format, t_list *l, va_list ap2)
{
	va_list	ap3;

	va_copy(ap3, ap2);
	l->index++;
	l->zero = ft_atoi(format + l->index);
	while (ft_isdigit(format[l->index]))
		l->index++;
	if (format[l->index] == 'd' || format[l->index] == 'i')
	{
		l->zero -= calcule_number(va_arg(ap2, int));
		if (va_arg(ap3, int) < 0)
		{
			l->counter += ft_putchar('-');
			l->is_minus = 1;
		}
	}
	else if (format[l->index] == 'u')
		l->zero -= calcule_number(va_arg(ap2, t_int));
	else if (format[l->index] == 'x' || format[l->index] == 'X')
		l->zero -= count_hexa(va_arg(ap2, t_int), format[l->index]);
	else if (format[l->index] == 'p')
		l->zero -= count_hexa((t_long) va_arg(ap2, void *), 'm') + 2;
	va_end(ap3);
}
