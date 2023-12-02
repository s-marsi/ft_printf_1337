/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:28:32 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/01 19:15:15 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	va_list	ap2;
	int		margin;
	int		counter;
	int		index;
}	t_list;
int			ft_printf(const char *format, ...);
int			ft_putstr(char *s);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putnbr_hexa(unsigned long n, char x);
int			check_bonus(const char *str, int *margin, int *print_zero);
int			ft_atoi(const char *str);
int			ft_toupper(int c);
int			ft_isdigit(int c);
int			ft_strlen(const char *s);
long		calcule_number(long n);
const char	*ft_itoa(unsigned long n);
void		*ft_calloc(size_t count, size_t size);
int			count_hexa(unsigned long n, char x);
int			find_flags(const char *format, t_list *list, va_list ap);

#endif