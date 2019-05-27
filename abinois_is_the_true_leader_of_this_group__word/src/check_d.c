/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/27 20:16:41 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** will malloc a new string if input is of type d or i
*/

char		*fill_str_d(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = F.nb < 0 ? ft_strlen(toa) - 1 : ft_strlen(toa);
	c = 0;
	if (F.minus)
	{
		res = p_toa(toa, p_zer(F.field, p_sign(&F, res, &c), &c, l_nb), &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
	{
		res = p_sign(&F, res, &c);
		res = p_toa(toa, p_zer(F.field, res, &c, l_nb), &c);
	}
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		res = p_toa(toa, p_zer(F.field, p_sign(&F, res, &c), &c, l_nb), &c);
	}
	return (res);
}

char		*malloc_str_d(t_flag flagz, va_list ap)
{
	char		*toa;
	char		*res;
	size_t		lmax;

	F.nb = check_d_i_flagz(flagz, ap);
	toa = ft_lltoa(F.nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > lmax)
		lmax = F.nb < 0 ? F.preci + 1 : F.preci;
	if (F.nb > 0 && (F.plus || F.sp) && F.field < lmax)
		lmax++;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	return ((res = fill_str_d(F, lmax, toa, res)));
}
