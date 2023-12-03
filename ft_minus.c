/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:04:57 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 21:54:01 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus(const char *format, t_list *l, va_list ap2)
{
	l->index++;
	l->margin = ft_atoi(format + l->index);
	if (format[l->index] == '.')
		ft_dot(format, l, ap2);
	while (ft_isdigit(format[l->index]))
		l->index++;
	if (format[l->index] == 'd' || format[l->index] == 'i')
		l->margin -= calcule_number(va_arg(ap2, int));
	else if (format[l->index] == 'c')
		l->margin -= 1;
	else if (format[l->index] == 's')
		l->margin -= ft_strlen(va_arg(ap2, char *));
	else if (format[l->index] == 'u')
		l->margin -= calcule_number(va_arg(ap2, t_int));
	else if (format[l->index] == 'x' || format[l->index] == 'X')
		l->margin -= count_hexa(va_arg(ap2, t_int), format[l->index]);
	else if (format[l->index] == 'p')
		l->margin -= count_hexa((t_long) va_arg(ap2, void *), 'm') + 2;
	else if (format[l->index] == '%')
		l->margin -= 1;
}
