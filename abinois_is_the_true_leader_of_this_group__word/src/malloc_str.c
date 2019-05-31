/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:06:44 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/29 13:40:06 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	*malloc_str_d(t_flag flagz, va_list ap)
{
	char	*toa;
	char	*res;
	size_t	lmax;

	F.nb = check_d_i_flagz(flagz, ap);
	if (!(toa = ft_lltoa(F.nb)))
		return (NULL);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > lmax)
		lmax = F.nb < 0 ? F.preci + 1 : F.preci;
	if (F.nb > 0 && (F.plus || F.sp) && F.field < lmax)
		lmax++;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
	{
		ft_memdel((void**)&toa);
		return (NULL);
	}
	res[lmax] = '\0';
	return ((res = fill_str_d(F, lmax, toa, res)));
}

char	*malloc_str_ou(t_flag flagz, va_list ap)
{
	ULL		nb;
	char	*toa;
	char	*res;
	size_t	lmax;

	nb = check_poux_flagz(F, ap);
	if (!(toa = (F.conv == 'o' ? ft_octatoa(nb) : ft_llutoa(nb))))
		return (NULL);
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
	{
		ft_memdel((void**)&toa);
		return (NULL);
	}
	res[lmax] = '\0';
	return ((res = fill_str_ou(F, lmax, toa, res)));
}

char	*malloc_str_xp(t_flag flagz, va_list ap)
{
	ULL		nb;
	char	*toa;
	char	*res;
	size_t	lmax;

	nb = check_poux_flagz(F, ap);
	if (!(toa = ft_hexatoa(nb)))
		return (NULL);
	lmax = ft_strlen(toa);
	if ((F.conv == 'x' && F.hash) || F.conv == 'p')
		lmax += 2;
	if (F.preci > lmax)
		lmax = F.hash ? F.preci + 2 : F.preci;
	if (F.field > lmax)
		lmax = F.field;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
	{
		ft_memdel((void**)&toa);
		return (NULL);
	}
	return ((res = fill_str_xp(F, lmax, toa, res)));
}

char	*malloc_str_s(t_flag flagz, va_list ap)
{
	char	*toa;
	char	*res;
	size_t	lmax;

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

char	*malloc_str_c(t_flag flagz, va_list ap, char option)
{
	char	c;
	size_t	lmax;
	char	*res;
	size_t	i;

	c = option == 1 ? '%' : (char)va_arg(ap, UI);
	i = 0;
	lmax = F.field > 1 ? F.field : 1;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	if (F.minus)
	{
		res[i++] = c == 0 ? -1 : c;
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
