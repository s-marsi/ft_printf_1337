/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:17:23 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/28 11:19:22 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	long	divider;
	int		count_return;

	count_return = 0;
	nb = n;
	if (nb < 0)
	{
		count_return += ft_putchar('-');
		nb = -nb;
	}
	divider = 1;
	while (nb / divider >= 10)
		divider *= 10;
	while (divider > 0)
	{
		n = (nb / divider) + '0';
		count_return += ft_putchar(n);
		nb = nb % divider;
		divider /= 10;
	}
	return (count_return);
}
