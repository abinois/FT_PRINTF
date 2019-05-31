/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:11:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/30 19:53:20 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int		ftrv;
	int		rv;
//	long double	a = 9.99;
	int		longo = 4040;

	(void)argc;
	(void)argv;
	ft_putstr("____ ftprintf ____\n");
	ftrv = ft_printf("%-+10.2d\n", longo);
	ft_printf("Return value = %d\n", ftrv); 
	ft_putstr("_____ printf _____\n");
	rv = printf("%-+10.2d\n", longo);
	ft_printf("Return value = %d\n", rv); 
	return (0);
}
