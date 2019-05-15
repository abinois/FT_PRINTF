/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:50:25 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/15 12:32:52 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** THIS FILE CONTAIN :
** put_hash > put a zero at the right place if hash flag is active.
** fill_str_u > fill the string depending on minus/field/zero/preci.
** fill_str_o > fill the string depending on minus/field/zero/preci/hash.
** malloc_str_u > malloc a len for the string depending on field/preci.
** malloc_str_o > malloc a len for the string depending on field/preci/hash.
*/

char		*put_hash(char *res, size_t *c, t_flag flagz)
{
	if (F.hash && *c == 0)
		res[(*c)++] = '0';
	else if (F.hash)
		res[(*c) - 1] = '0';
	return (res);
}

char		*fill_str_u(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = ft_strlen(toa);
	c = 0;
	if (F.minus)
	{
		res = put_toa(toa, put_zer(F.preci, res, &c, l_nb), &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
		res = put_toa(toa, put_zer(F.field, res, &c, l_nb), &c);
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		res = put_toa(toa, put_zer(F.preci, res, &c, l_nb), &c);
	}
	return (res);
}

char		*fill_str_o(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = ft_strlen(toa);
	c = 0;
	if (F.minus)
	{
		res = put_zer(F.preci, res, &c, l_nb);
		res = put_toa(toa, put_hash(res, &c, F), &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
		res = put_toa(toa, put_zer(F.field, res, &c, l_nb), &c);
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		res = put_zer(F.preci, res, &c, l_nb);
		res = put_toa(toa, put_hash(res, &c, F), &c);
	}
	return (res);
}

char		*malloc_str_o(t_flag flagz, va_list ap, char conv)
{
	unsigned int	nb;
	char			*toa;
	char			*res;
	size_t			lmax;

	nb = check_u_flagz(F, ap, conv);
	toa = ft_octatoa(nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > lmax)
		lmax = F.preci;
	if (F.hash && F.preci <= ft_strlen(toa) && F.field < ft_strlen(toa))
		lmax++;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	return ((res = fill_str_o(F, lmax, toa, res)));
}

char		*malloc_str_u(t_flag flagz, va_list ap, char conv)
{
	ULL			nb;
	char		*toa;
	char		*res;
	size_t		lmax;

	nb = check_u_flagz(F, ap, conv);
	toa = ft_llutoa(nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > lmax)
		lmax = F.preci;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	return ((res = fill_str_u(F, lmax, toa, res)));
}
