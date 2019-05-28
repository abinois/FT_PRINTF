/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:11:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/28 20:47:54 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{

	long double	a = 9.99;
	(void)argc;
	(void)argv;
	ft_putstr("_____ ft_printf _____\n");
	ft_printf("% #21.30Lf\n", a);
	ft_putstr("_____ printf _____\n");
	printf("% #21.30Lf\n", a);
	return (0);
}
