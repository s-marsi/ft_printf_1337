/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:34:29 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/30 18:26:50 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	calcule_number(long n)
{
	long	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
