/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:37 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 21:04:17 by abinois          ###   ########.fr       */
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

char		*fill_str_u(t_flag F, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = ft_strlen(toa);
	c = 0;
	if (F.minus)
	{
		if (F.preci > l_nb)
			while (l_nb++ < F.preci)
				res[c++] = '0';
		res = put_toa(toa, res, &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
	{
		if (F.field > l_nb)
			while (l_nb++ < F.field)
				res[c++] = '0';
		res = put_toa(toa, res, &c);
	}
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		if (F.preci > l_nb)
			while (l_nb++ < F.preci)
				res[c++] = '0';
		res = put_toa(toa, res, &c);
	}
	return (res);
}

ULL	check_u_flagz(t_flag F, va_list ap)
{
	ULL	number;

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

char		*malloc_str_u(t_flag F, va_list ap)
{
	ULL			nb;
	char		*toa;
	char		*res;
	size_t		lmax;

	nb = check_u_flagz(F, ap);
	toa = ft_llutoa(nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (lmax < F.preci >= F.field)
		lmax = F.preci;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	return ((res = fill_str_u(F, lmax, toa, res)));
}
