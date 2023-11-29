/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:45:33 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/29 16:09:36 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	nb;
	unsigned int	divider;
	int				count_return;

	count_return = 0;
	nb = n;
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
