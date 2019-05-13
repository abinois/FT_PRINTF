/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:37 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 19:33:05 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** THIS IS CHECK_U.C
*/

char	*put_toa(char *toa, char *res, size_t *c)
{
	while (*toa)
		res[(*c)++] = *toa++;
	return (res);
}

char		*fill_str_u(t_flag flagz, size_t lmax, char *toa)
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
		res = put_toa(toa, res, &c);
		if (flagz.field > flagz.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (flagz.zer == true && flagz.dot == false)
	{
		if (flagz.field > l_nb)
			while (l_nb++ < flagz.field)
				res[c++] = '0';
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
		res = put_toa(toa, res, &c);
	}
	return (res);
}

ULL	check_u_flagz(t_flag flagz, va_list ap)
{
	ULL	number;

	if (flagz.l == true)
		return ((number = va_arg(ap, unsigned long)));
	if (flagz.ll == true)
		return ((number = va_arg(ap, ULL)));
	if (flagz.h == true)
		return ((number = (unsigned short)va_arg(ap, UI)));
	if (flagz.hh == true)
		return ((number = (unsigned char)va_arg(ap, UI)));
	return ((number = va_arg(ap, unsigned int)));
}

char		*malloc_str_u(t_flag flagz, va_list ap)
{
	ULL			nb;
	char		*toa;
	char		*result;
	size_t		lmax;

	nb = check_u_flagz(flagz, ap);
	toa = ft_llutoa(nb);
	lmax = ft_strlen(toa);
	if (flagz.field > lmax)
		lmax = flagz.field;
	if (flagz.preci >= flagz.field && flagz.preci > lmax)
		lmax = flagz.preci;
	return ((result = fill_str_u(flagz, lmax, toa)));
}
