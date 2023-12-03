/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:40:41 by smarsi            #+#    #+#             */
/*   Updated: 2023/12/03 22:04:53 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <limits.h>
int	main(void)
{
	// int	a;
	// int	b;
	// a = ft_printf("%1s", "");
	// b = printf("%1s", "");
	// printf ("%d\n%d\n", a, b);
	// printf("\n");
	// int a = ft_printf("a% sa", "hello");
	// printf("\n============ \n");
	// int b = printf("a% sa", "hello");
	// printf("\n%d\n%d\n", a,b);
	int c = ft_printf("a% d\n", -10);
	printf("\n");
	int d = printf("a% d\n", -10);
	printf("\n");
	printf("\n%d\n%d\n",c, d);
	return (0);
}
