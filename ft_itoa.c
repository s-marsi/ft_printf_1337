/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:02:33 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/30 18:23:28 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long	count_number(long n)
{
	long	count;

	count = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	const char	*to_string(char *str, long nb, int n, unsigned long len)
{
	int	divided;

	if (n < 0)
		str[0] = '-';
	divided = 10;
	while (len--)
	{
		if (n < 0 && len == 0)
			return (str);
		str[len] = (nb % divided) + '0';
		nb /= 10;
	}
	return ((const char *)str);
}

const char	*ft_itoa(unsigned long n)
{
	unsigned long	count;
	char			*str;

	count = 0;
	count = count_number(n);
	str = malloc(count + 1 * sizeof(char));
	str[n] = '\0';
	if (!str)
		return (NULL);
	return (to_string(str, n, n, count));
}
