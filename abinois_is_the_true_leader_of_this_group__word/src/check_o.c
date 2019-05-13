/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:50:25 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 18:26:49 by edillenb         ###   ########.fr       */
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

char		*fill_str_o(t_flag flagz, unsigned int nb, size_t lmax, char *toa)
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
	if (flagz.minus == true)
	{
		if (flagz.preci > l_nb)
			while (l_nb++ < flagz.preci)
				res[c++] = '0';
		if (flagz.hash == true && c == 0)
			res[c++] = '0';
		res = put_toa(toa, res, &c);
		if (flagz.field > flagz.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	/*
	else if (flagz.zer == true && flagz.dot == false)
	{
		if (flagz.field > l_nb)
			while (l_nb++ < flagz.field)
				res[c++] = '0';
		if (flagz.hash == true && c == 0)
			res[c++] = '0';
		else if (flagz.hash == true)
			res[c - 1] = '0';
		res = put_toa(toa, res, &c);
	}
	else
	{
		if (flagz.field > l_nb && flagz.field > flagz.preci)
			while (c < flagz.field - (flagz.preci > l_nb ? flagz.preci : l_nb))
				res[c++] = ' ';
		if (flagz.preci > l_nb)
			while (l_nb++ < flagz.preci)
				res[c++] = '0';
		if (flagz.hash == true && c == 0)
			res[c++] = '0';
		else if (flagz.hash == true)
			res[c - 1] = '0';
		res = put_toa(toa, res, &c);
	}
	*/
	else
	{
		if (flagz.zer == true && flagz.dot == false && flagz.field > l_nb)
			while (l_nb++ < flagz.field)
				res[c++] = '0';
		else
		{
			if (flagz.field > l_nb && flagz.field > flagz.preci)
				while (c < flagz.field - (flagz.preci > l_nb ? flagz.preci : l_nb))
					res[c++] = ' ';
			if (flagz.preci > l_nb)
				while (l_nb++ < flagz.preci)
					res[c++] = '0';
		}
		if (flagz.hash == true && c == 0)
			res[c++] = '0';
		else if (flagz.hash == true)
			res[c - 1] = '0';
		res = put_toa(toa, res, &c);
	}
	return (res);
}

unsigned int	check_o_flagz(t_flag flagz, va_list ap)
{
	unsigned int	number;

	if (flagz.l == true)
		return ((number = va_arg(ap, unsigned long)));
	if (flagz.ll == true)
		return ((number = va_arg(ap, ULL)));
	if (flagz.h == true)
		return ((number = (unsigned short)va_arg(ap, unsigned int)));
	if (flagz.hh == true)
		return ((number = (unsigned char)va_arg(ap, unsigned int)));
	return ((number = va_arg(ap, unsigned int)));
}

char		*malloc_str_o(t_flag flagz, va_list ap)
{
	unsigned int	nb;
	char			*toa;
	char			*result;
	size_t			lmax;

	nb = check_u_flagz(flagz, ap);
	toa = ft_uioctaltoa(nb);
	lmax = ft_strlen(toa);
	if (flagz.field > lmax)
		lmax = flagz.field;
	if (flagz.preci >= flagz.field && flagz.preci > lmax)
		lmax = flagz.preci;
	if (flagz.hash && flagz.preci <= ft_strlen(toa) >= flagz.field)
		lmax++;
	return ((result = fill_str_o(flagz, nb, lmax, toa)));
}
