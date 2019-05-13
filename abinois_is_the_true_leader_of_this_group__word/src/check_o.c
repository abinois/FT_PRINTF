/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:50:25 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 20:23:00 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** THIS IS CHECK_O.C
*/

char		*fill_str_o(t_flag F, size_t lmax, char *toa)
{
	char	*res;
	size_t	l_nb;
	size_t	len;
	size_t	c;

	len = ft_strlen(toa);
	l_nb = len;
	c = 0;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	if (F.minus)
	{
		if (F.preci > l_nb)
			while (l_nb++ < F.preci)
				res[c++] = '0';
		if (F.hash && c == 0)
			res[c++] = '0';
		res = put_toa(toa, res, &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else
	{
		if (F.zer && !(F.dot) && F.field > l_nb)
			while (l_nb++ < F.field)
				res[c++] = '0';
		else
		{
			if (F.field > l_nb && F.field > F.preci)
				while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
					res[c++] = ' ';
			if (F.preci > l_nb)
				while (l_nb++ < F.preci)
					res[c++] = '0';
		}
		if (F.hash && c == 0)
			res[c++] = '0';
		else if (F.hash)
			res[c - 1] = '0';
		res = put_toa(toa, res, &c);
	}
	return (res);
}

unsigned int	check_o_flagz(t_flag F, va_list ap)
{
	unsigned int	number;

	if (F.l)
		return ((number = va_arg(ap, unsigned long)));
	if (F.ll)
		return ((number = va_arg(ap, ULL)));
	if (F.h)
		return ((number = (unsigned short)va_arg(ap, UI)));
	if (F.hh)
		return ((number = (unsigned char)va_arg(ap, UI)));
	return ((number = va_arg(ap, UI)));
}

char		*malloc_str_o(t_flag F, va_list ap)
{
	unsigned int	nb;
	char			*toa;
	char			*result;
	size_t			lmax;

	nb = check_u_flagz(F, ap);
	toa = ft_octatoa(nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > lmax)
		lmax = F.preci;
	if (F.hash && F.preci <= ft_strlen(toa) >= F.field)
		lmax++;
	return ((result = fill_str_o(F, lmax, toa)));
}
