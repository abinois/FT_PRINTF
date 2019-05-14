/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:29:23 by abinois           #+#    #+#             */
/*   Updated: 2019/05/14 11:11:08 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

char	*fill_str_xX(t_flag F, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = ft_strlen(toa);
	c = 0;
	res[lmax] = '\0';
	if (F.minus)
	{
		if (F.hash)
			res = put_toa("0x", res, &c);
		if (F.preci > l_nb)
			while (l_nb++ < F.preci)
				res[c++] = '0';
		res = put_toa(toa, res, &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else
	{
		if (F.zer && !(F.dot) && F.field > l_nb)
		{
			if (F.hash)
				res = put_toa("0x", res, &c);
			while (c < F.field - (F.hash ? l_nb - 2 : l_nb))
				res[c++] = '0';
		}
		else
		{
			if (F.field > F.preci && F.field > l_nb)
				while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
					res[c++] = ' ';
			if (F.hash && c > 0)
				c -= 2;
			res = put_toa("0x", res, &c);
			if (F.preci > l_nb)
				while (l_nb++ < F.preci)
					res[c++] = '0';
		}
		res = put_toa(toa, res, &c);
	}
	return (res);
}

char	*malloc_str_xX(t_flag F, va_list ap)
{
	UI		nb;
	char	*toa;
	char	*result;
	size_t	lmax;

	nb = check_u_flagz(F, ap);
	toa = ft_hexatoa(nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > ft_strlen(toa))
		lmax = F.preci;
	if (F.hash && F.preci <= ft_strlen(toa) && F.field <= ft_strlen(toa))
		lmax += 2;
	if (!(result = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	return ((result = fill_str_xX(F, lmax, toa, result)));
}
