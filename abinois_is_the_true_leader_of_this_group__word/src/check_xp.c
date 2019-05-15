/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:29:23 by abinois           #+#    #+#             */
/*   Updated: 2019/05/15 18:35:12 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

char	*fill_nomin_xp(t_flag flagz, size_t l_nb, char *res, size_t *c)
{
	if (F.zer && !(F.dot) && F.field > l_nb)
	{
		if (F.hash)
			res = p_toa("0x", res, c);
		while (*c < F.field - l_nb)
			res[(*c)++] = '0';
	}
	else
	{
		if (F.field > F.preci && F.field > l_nb)
			while (*c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[(*c)++] = ' ';
		if (F.hash)
		{
			if (*c >= 2)
				(*c) -= 2;
			else
				(*c) -= *c;
			res = p_toa("0x", res, c);
		}
		res = p_zer(F.preci, res, c, l_nb);
	}
	return (res);
}

char	*fill_str_xp(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = ft_strlen(toa);
	c = 0;
	res[lmax] = '\0';
	if (F.minus)
	{
		if (F.hash)
			res = p_toa("0x", res, &c);
		res = p_toa(toa, p_zer(F.preci, res, &c, l_nb), &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else
	{
		fill_nomin_xp(F, l_nb, res, &c);
		res = p_toa(toa, res, &c);
	}
	return (res);
}

char	*malloc_str_xp(t_flag flagz, va_list ap)
{
	ULL		nb;
	char	*toa;
	char	*res;
	size_t	lmax;

	nb = check_poux_flagz(F, ap);
	toa = llhexatoa(nb);
	lmax = ft_strlen(toa);
	if ((F.conv == 'x' && F.hash) || F.conv == 'p')
		lmax += 2;
	if (F.preci > lmax)
		lmax = F.hash ? F.preci + 2 : F.preci;
	if (F.field > lmax)
		lmax = F.field;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	return ((res = fill_str_xp(F, lmax, toa, res)));
}
