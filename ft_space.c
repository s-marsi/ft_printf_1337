/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:40:17 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 18:51:52 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space(const char *format, t_list *l, va_list ap2)
{
	int	nb;

	l->index++;
	if (format[l->index] == 'd' || format[l->index] == 'i')
	{
		nb = va_arg(ap2, int);
		if (nb >= 0)
			l->counter += ft_putchar(' ');
	}
}
