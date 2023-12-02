/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:24:18 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/01 23:12:31 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hexa(unsigned long n, char x)
{
	int		count_return;
	char	*base;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	count_return = 0;
	if (n < 16)
		count_return += 1;
	else
	{
		count_return += count_hexa(n / 16, x);
		count_return += 1;
	}
	return (count_return);
}
