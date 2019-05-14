/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/14 11:07:49 by abinois          ###   ########.fr       */
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

char		*put_sign(t_flag F, long long nb, char *res, size_t *c)
{
	if (nb < 0)
		res[(*c)++] = '-';
	else if (F.plus && nb >= 0)
		res[(*c)++] = '+';
	else if (F.sp && nb >= 0)
		res[(*c)++] = ' ';
	return (res);
}

char		*fill_string(t_flag F, long long nb, size_t lmax, char *lltoa)
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
	if (F.minus)
	{
		res = put_sign(F, nb, res, &c);
		if (F.preci > l_nb)
			while (l_nb++ < F.preci)
				res[c++] = '0';
		res = put_toa(lltoa, res, &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
	{
		res = put_sign(F, nb, res, &c);
		if (F.field > l_nb)
			while (l_nb++ < (c > 0) ? F.field - 1 : F.field)
				res[c++] = '0';
		res = put_toa(lltoa, res, &c);
	}
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		if ((nb < 0 || F.plus || F.sp) && c != 0)
			c--;
		res = put_sign(F, nb, res, &c);
		if (F.preci > l_nb)
			while (l_nb++ < F.preci)
				res[c++] = '0';
		res = put_toa(lltoa, res, &c);
	}
	return (res);
}

long long	check_d_i_flagz(t_flag F, va_list ap)
{
	long long	number;

	if (F.l)
		return ((number = va_arg(ap, long)));
	if (F.ll)
		return ((number = va_arg(ap, long long)));
	if (F.h)
		return ((number = (short)va_arg(ap, int)));
	if (F.hh)
		return ((number = (char)va_arg(ap, int)));
	return ((number = va_arg(ap, int)));
}

char		*malloc_str_d_i(t_flag F, va_list ap)
{
	long long	nb;
	char		*lltoa;
	char		*result;
	size_t		len;

	nb = check_d_i_flagz(F, ap);
	lltoa = ft_lltoa(nb);
	len = ft_strlen(lltoa);
	if (F.field > len)
		len = F.field;
	if (F.preci >= F.field && F.preci > len)
		len = nb < 0 ? F.preci + 1 : F.preci;
	if (nb > 0 && (F.plus || F.sp) && F.field < len)
		len++;
	return ((result = fill_string(F, nb, len, lltoa)));
}
