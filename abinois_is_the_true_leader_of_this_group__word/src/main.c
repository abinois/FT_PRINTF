/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:11:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/06/03 11:52:42 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <float.h>

int		main(int argc, char **argv)
{
	int			ftrv;
	int			rv;
	//long double	a;
	int		b;

	(void)argc;
	(void)argv;
	//a = 9.99;
	b = 0;
	ft_putstr("____ ftprintf ____\n");
	ftrv = ft_printf("%5.x %5.0x", 0, 0);
	printf("Return value = %d\n", ftrv); 
	ft_putstr("_____ printf _____\n");
	rv = printf("%5.x %5.0x", 0, 0);
	printf("Return value = %d\n", rv); 
	return (0);
}
