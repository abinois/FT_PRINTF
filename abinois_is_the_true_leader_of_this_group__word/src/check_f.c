/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/24 19:13:19 by edillenb         ###   ########.fr       */
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

char	*over_63(t_float *infloat, char *res, int x, int i)
{
	char	*buffer;

	if (!(buffer = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	buffer = "1\0";
	while (++x <= (int)infloat->expo - i)
		if (!(buffer = str_times_two(buffer)))
			return (NULL);
	if ((infloat->mantissa)[i] == '1')
		if (!(res = str_add(buffer, res)))
			return (NULL);
	x = 1;
	while (--i >= 0)
	{
		if ((infloat->mantissa)[i] == '1')
		{
			while (x-- > 0)
				if (!(buffer = str_times_two(buffer)))
					return (NULL);
			if (!(res = str_add(buffer, res)))
				return (NULL);
			x = 1;
		}
		else
			x++;
	}
	free(buffer); 
	return (res);
}

char	*deci_float(t_float *infloat)
{
	char		*res;
	char		*buffer;
	int	i;
	int	x;

	x = 0;
	i = 0;
	while ((int)infloat->expo - i > 0 && i < 63)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	res = "0\0"; 
	while (i >= 0 && (int)infloat->expo - i <= 63)
	{
		if ((infloat->mantissa)[i] == '1')
			if (!(res = str_add(res, ft_llutoa(ft_pow(2, (int)infloat->expo - i)))))
				return (NULL);
		i--;
	}
	if (i >= 0 && (int)infloat->expo - i > 63)	
		if (!(res = over_63(infloat, res, x, i)))
			return (NULL);
	return (res);
}

char		*get_float(t_flag flagz, va_list ap)
{
	long double	nb;
	t_float		*infloat;

	if (!(infloat = (t_float *)malloc(sizeof(t_float))))
		return (NULL);
	nb = check_f_flagz(F, ap);
	infloat->mantissa = get_mantissa(nb);
	infloat->expo = get_exponent(nb);
	infloat->sign = nb >= 0 ? false : true;
	infloat->result = deci_float(infloat);
	return (infloat->result);
}

