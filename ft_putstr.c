/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:07:10 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/30 17:37:16 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count_return;

	count_return = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		count_return += ft_putchar(*s);
		s++;
	}
	return (count_return);
}
