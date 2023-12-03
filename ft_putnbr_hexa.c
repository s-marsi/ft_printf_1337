/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:35:58 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:04 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, char x)
{
	int		count_return;
	char	*base;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	count_return = 0;
	if (n < 16)
		count_return += ft_putchar(base[n % 16]);
	else
	{
		count_return += ft_putnbr_hexa(n / 16, x);
		count_return += ft_putchar(base[n % 16]);
	}
	return (count_return);
}
