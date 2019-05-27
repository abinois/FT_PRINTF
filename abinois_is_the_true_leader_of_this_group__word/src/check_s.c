/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:33:17 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/27 20:16:07 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** THIS IS CHECK_S.C
*/

char	*fill_str_s(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_toa;
	size_t	c;

	l_toa = ft_strlen(toa);
	if (F.dot)
		l_toa = F.preci < l_toa ? F.preci : l_toa;
	c = 0;
	if (F.minus)
	{
		while (l_toa--)
			res[c++] = *toa++;
		while (c < lmax)
			res[c++] = ' ';
	}
	else
	{
		if (F.field > l_toa)
			while (c < F.field - l_toa)
				res[c++] = F.zer ? '0' : ' ';
		while (l_toa--)
			res[c++] = *toa++;
	}
	return (res);
}

char	*malloc_str_s(t_flag flagz, va_list ap)
{
	char		*toa;
	char		*res;
	size_t		lmax;

	toa = va_arg(ap, char*);
	lmax = ft_strlen(toa);
	if (F.dot)
		lmax = F.preci < lmax ? F.preci : lmax;
	if (F.field > lmax)
		lmax = F.field;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	return ((res = fill_str_s(F, lmax, toa, res)));
}

char	*malloc_str_c(t_flag flagz, va_list ap)
{
	char	c;
	size_t	lmax;
	char	*res;
	size_t	i;

	c = (char)va_arg(ap, UI);
	i = 0;
	lmax = F.field > 1 ? F.field : 1;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	if (F.minus)
	{
		res[i++] = c;
		while (i < F.field)
			res[i++] = ' ';
	}
	else
	{
		while (F.field > 1 && i < F.field - 1)
			res[i++] = (F.zer ? '0' : ' ');
		res[i] = c;
	}
	return (res);
}
