/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/23 15:12:57 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

char	*get_mantissa(long double dbl)
{
	uint8_t		*nb;
	char		*binary;
	int			i;
	size_t		size;
	uint8_t		mask;

	nb = (uint8_t*)&dbl;
	i = 0;
	size = 65;
	if (!(binary = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	binary[--size] = '\0';
	while (i < 8)
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
	return (binary);
}

uint16_t	get_exponent(long double dbl)
{
	uint16_t	mask;
	uint16_t	*nb;

	mask = 32767;
	nb = (uint16_t*)&dbl;
	nb += 4;
	*nb &= mask;
	*nb -= 16383;
	return (*nb);
}

char		*get_float(long double dbl, t_flag flagz, va_list ap)
{
	long double	nb;
	t_float		*float_data;

	nb = check_f_flagz(F, ap);
	float_data->mantissa = get_mantissa(nb);
	float_data->expo = get_exponent(nb);
	float_data->sign = dbl > 0 ? false : true;
	return (float_data->result);
}