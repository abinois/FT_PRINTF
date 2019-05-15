/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:33:17 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/15 10:19:27 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** THIS IS CHECK_S.C
*/

char	*fill_str_s(t_flag flagz, size_t lmax, char *toa, char *res)
{
	size_t	l_nb;
	size_t	c;

	l_nb = F.preci < ft_strlen(toa) ? F.preci : ft_strlen(toa);
	c = 0;
	if (F.minus)
	{
		while (l_nb--)
			res[c++] = *toa++;
		while (c < lmax)
			res[c++] = ' ';
	}
	else
	{
		if (F.field > l_nb)
			while (c < F.field - l_nb)
				res[c++] = F.zer ? '0' : ' ';
		while (l_nb--)
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
	lmax = F.preci < ft_strlen(toa) ? F.preci : ft_strlen(toa);
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
