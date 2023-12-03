/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:31:35 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/02 23:40:35 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sharp(const char *format, t_list *l, va_list ap2)
{
	unsigned int	nb;

	l->index++;
	nb = va_arg(ap2, unsigned int);
	if (nb != 0 && format[l->index] == 'x')
		l->counter += ft_putstr("0x");
	if (nb != 0 && format[l->index] == 'X')
		l->counter += ft_putstr("0X");
}