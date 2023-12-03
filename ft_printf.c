/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:41:18 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 21:26:37 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_str(const char *src, t_list *l)
{
	l->counter = 0;
	l->index = 0;
	while (src[l->index])
	{
		if (src[l->index] == '%')
		{
			l->index++;
			find_flags(src, l);
		}
		else
			l->counter += ft_putchar(src[l->index]);
		l->index++;
		l->is_dot = 0;
	}
}

int	ft_printf(const char *format, ...)
{
	t_list	l;

	l.is_minus = 0;
	l.is_dot = 0;
	va_start(l.ap, format);
	fill_str(format, &l);
	va_end(l.ap);
	return (l.counter);
}
