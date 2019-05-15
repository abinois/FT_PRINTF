/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:50:25 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/15 18:34:32 by edillenb         ###   ########.fr       */
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

char		*put_hash(char *res, size_t *c, t_flag flagz, size_t l_nb)
{
	res = p_zer(F.preci, res, c, l_nb);
	if (F.conv == 'o')
	{
		if (F.hash && *c == 0)
			res[(*c)++] = '0';
		else if (F.hash)
			res[(*c) - 1] = '0';
	}
	return (res);
}

char		*fill_str_ou(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = ft_strlen(toa);
	c = 0;
	if (F.minus)
	{
		res = p_toa(toa, put_hash(res, &c, F, l_nb), &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
		res = p_toa(toa, p_zer(F.field, res, &c, l_nb), &c);
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		res = p_toa(toa, put_hash(res, &c, F, l_nb), &c);
	}
	return (res);
}

char		*malloc_str_ou(t_flag flagz, va_list ap)
{
	ULL				nb;
	char			*toa;
	char			*res;
	size_t			lmax;

	nb = check_poux_flagz(F, ap);
	if (F.conv == 'o')
		toa = ft_octatoa(nb);
	else
		toa = ft_llutoa(nb);
	lmax = ft_strlen(toa);
	if (F.conv == 'o' && F.hash)
		lmax++;
	if (F.conv == 'o' && F.preci > lmax)
		lmax = F.hash ? F.preci + 1 : F.preci;
	if (F.conv == 'u' && F.preci > lmax)
		lmax = F.preci;
	if (F.field > lmax)
		lmax = F.field;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	return ((res = fill_str_ou(F, lmax, toa, res)));
}
