/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:28:13 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/29 20:33:43 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	static	check_arg(const char *str, va_list ap)
{
	int		count;
	int		i;
	char	c;

	i = 0;
	count = 0;
	if (str[i] == 'c')
	{
		c = va_arg(ap, int);
		count += write(1, &c, 1);
	}
	else if (str[i] == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_putnbr_hexa(va_arg(ap, unsigned int), str[i]);
	else if (str[i] == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hexa((unsigned long) va_arg(ap, void *), 'm');
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count_return;	
	int		margin;
	
	i = 0;
	margin = 0;
	count_return = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == '%'))
			count_return += write(1, str + ++i, 1);
		else if (str[i] == '%')
		{
			i++;
			if (str[i] == '-')
			{
				i++;
				i += ft_margin(str + i, &margin);
			}
			count_return += check_arg(str + i++, ap);
		}
		else
		{
			count_return += write(1, str + i, 1);
		}
		while (margin)
		{
			count_return += write(1, " ", 1);
			margin--;
		}
		i++;
	}
	va_end(ap);
	return (count_return);
}
