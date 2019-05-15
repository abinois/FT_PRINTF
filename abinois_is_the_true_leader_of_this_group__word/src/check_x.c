/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:29:23 by abinois           #+#    #+#             */
/*   Updated: 2019/05/15 13:45:42 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

char	*fill_str_x(t_flag flagz, size_t lmax, char *toa, char *res)
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
		res = put_toa(toa, put_zer(F.preci, res, &c, l_nb), &c);
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
			while (c < F.field - l_nb)
				res[c++] = '0';
		}
		else
		{
			if (F.field > F.preci && F.field > l_nb)
				while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
					res[c++] = ' ';
			if (F.hash)
			{
				if (c >= 2)
					c -= 2;
				else
					c -= c; 
				res = put_toa("0x", res, &c);
			}
			res = put_zer(F.preci, res, &c, l_nb);
		}
		res = put_toa(toa, res, &c);
	}
	return (res);
}

char	*malloc_str_xp(t_flag flagz, va_list ap, char conv)
{
	ULL		nb;
	char	*toa;
	char	*res;
	size_t	lmax;

	nb = check_u_flagz(F, ap, conv);
	toa = llhexatoa(nb);
	lmax = ft_strlen(toa);
	if ((conv == 'x' && F.hash) || conv == 'p')
		lmax += 2;
	if (F.preci > lmax)
		lmax = F.preci;
	if (F.field > lmax)
		lmax = F.field;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	return ((res = fill_str_x(F, lmax, toa, res)));
}
