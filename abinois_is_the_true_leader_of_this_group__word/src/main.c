/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:11:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/06/04 10:37:13 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <float.h>

int		main(int argc, char **argv)
{
	int			rv;
	//long double	a;
//	int		b;

	(void)argc;
	(void)argv;
	//a = 9.99;
//	b = 0;
	ft_putstr("____ ftprintf ____\n");
	rv = ft_printf("{yellow}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{red}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{blue}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{green}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{cyan}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{magenta}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{black}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	rv = ft_printf("{under}joli %s{reset}\n", "haha");
	printf("Return value = %d\n", rv); 
	ft_putstr("_____ printf _____\n");
	rv = printf("joli %s\n", "haha");
	printf("Return value = %d\n", rv); 
	return (0);
}
