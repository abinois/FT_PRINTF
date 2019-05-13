/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 17:19:18 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** will malloc a new string if input is of type d or i
*/

char		*put_sign(t_flag flagz, long long nb, char *res, size_t *c)
{
	if (nb < 0)
		res[(*c)++] = '-';
	else if (flagz.plus == true && nb >= 0)
		res[(*c)++] = '+';
	else if (flagz.sp == true && nb >= 0)
		res[(*c)++] = ' ';
	return (res);
}

char		*fill_string(t_flag flagz, long long nb, size_t lmax, char *lltoa)
{
	char	*res;
	size_t	l_nb;
	size_t	len;
	size_t	c;

	len = ft_strlen(lltoa);
	l_nb = nb >= 0 ? len : len - 1;
	lltoa += nb < 0 ? 1 : 0;
	c = 0;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	if (flagz.minus == true)
	{
		res = put_sign(flagz, nb, res, &c);
		if (flagz.preci > l_nb)
			while (l_nb++ < flagz.preci)
				res[c++] = '0';
		res = put_toa(lltoa, res, &c);
		if (flagz.field > flagz.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (flagz.zer == true && flagz.dot == false)
	{
		res = put_sign(flagz, nb, res, &c);
		if (flagz.field > l_nb)
			while (l_nb++ < (c > 0) ? flagz.field - 1 : flagz.field)
				res[c++] = '0';
		res = put_toa(lltoa, res, &c);
	}
	else
	{
		if (flagz.field > l_nb && flagz.field > flagz.preci)
			while (c < flagz.field - (flagz.preci > l_nb ? flagz.preci : l_nb))
				res[c++] = ' ';
		if ((nb < 0 || flagz.plus == true || flagz.sp == true) && c != 0)
			c--;
		res = put_sign(flagz, nb, res, &c);
		if (flagz.preci > l_nb)
			while (l_nb++ < flagz.preci)
				res[c++] = '0';
		res = put_toa(lltoa, res, &c);
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
		return ((number = (char)va_arg(ap, int)));
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
	if (flagz.preci >= flagz.field && flagz.preci > len)
		len = nb < 0 ? flagz.preci + 1 : flagz.preci;
	if (nb > 0 && (flagz.plus == true || flagz.sp == true) && flagz.field < len)
		len++;
	return ((result = fill_string(flagz, nb, len, lltoa)));
}
