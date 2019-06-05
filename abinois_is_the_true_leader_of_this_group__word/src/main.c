/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:11:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/06/05 15:26:40 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <float.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int				rv;
	int				fd;
//	long double		a = -8.00;

	(void)argc;
	fd = open(argv[1], O_WRONLY);
	ft_putstr_fd("____ ftprintf ____\n", 1);
	rv = ft_printf("_____%c_____", 0);
	ft_printf("Return value = %d\n", rv); 
	ft_putstr_fd("_____ printf _____\n", 1);
	rv = printf("_____%c_____", 0);
	ft_printf("Return value = %d\n", rv); 
	return (0);
}
