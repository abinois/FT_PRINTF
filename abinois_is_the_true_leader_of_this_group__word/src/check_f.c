/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/22 18:19:42 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 ** THIS IS CHECK F
 */

long double	check_f_flagz(t_flag flagz, va_list ap)
{
	long double	number;

	if (F.bigl)
		return ((number = va_arg(ap, long double)));
	return ((number = va_arg(ap, double)));
}

char	*ldbltobinary(long double dbl)
{
	uint8_t		*nb;
	char		*binary;
	int			i;
	size_t		size;
	uint8_t		mask;

	nb = (uint8_t*)&dbl;
	i = 0;
	size = 81;
	if (!(binary = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	binary[--size] = '\0';
	while (i < 10)
	{
		mask = 1;
		while (mask)
		{
			binary[--size] = mask & *nb ? 1 + '0' : 0 + '0';
			mask <<= 1;
		}
		i++;
		nb++;
	}
	ft_putstrclr(binary, "blue");
	return (binary);
}
