/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 23:04:12 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** will malloc a new string if input is of type d or i
*/

char		*fill_string(t_flag flagz, long long nb, size_t len, char *lltoa)
{
	char	*res;
	size_t	i;
	size_t	len_nb;
	size_t	c;

	len_nb = nb >= 0 ? ft_strlen(lltoa) : ft_strlen(lltoa) - 1;
	i = 0;
	c = 0;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (flagz.minus == true && nb < 0)
		res[i++] = '-'; 
	else if (flagz.minus == true && flagz.plus == true && nb >= 0)
		res[0] = '+'; 
	else if (flagz.minus == true && flagz.sp == true && nb >= 0)
		res[0] = ' ';
	if (flagz.minus == true && flagz.preci > len_nb)
	{
		while (c <= flagz.preci - len_nb)
			res[++c] = '0';
		while (lltoa[i])
			res[c++] = lltoa[i++];
	}
	if (flagz.minus == true && flagz.preci < len_nb)
	{
		c = 1;
		while (lltoa[i])
			res[c++] = lltoa[i++];
	}
	if (flagz.minus == true && flagz.field > flagz.preci)
	{
		while (c < len)
			res[c++] = ' ';
	}
	return (res);
}

long long	check_d_i_flagz(t_flag flagz, va_list ap)
{
	long long	number;

	if (flagz.l == true)
		return ((number = va_arg(ap, long)));
	if (flagz.ll == true)
		return ((number = va_arg(ap, long long)));
	if (flagz.h == true)
		return ((number = (short)va_arg(ap, int)));
	if (flagz.hh == true)
		return ((number = (unsigned char)va_arg(ap, int)));
	return ((number = va_arg(ap, int)));
}

char		*malloc_str_d_i(t_flag flagz, va_list ap)
{
	long long	nb;
	char		*lltoa;
	char		*result;
	size_t		len;

	nb = check_d_i_flagz(flagz, ap);
	lltoa = ft_lltoa(nb);
	len = ft_strlen(lltoa);
	if (flagz.field > len)
		len = flagz.field;
	if (flagz.preci >= flagz.field)
		len = nb < 0 ? flagz.preci + 1 : flagz.preci;
	if (nb > 0 && (flagz.plus == true || flagz.sp == true) && flagz.field < len)
		len++;
	return ((result = fill_string(flagz, nb, len, lltoa)));
}
