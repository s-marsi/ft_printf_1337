/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:28:32 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/29 16:05:59 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_hexa(unsigned long n, char x);
#endif