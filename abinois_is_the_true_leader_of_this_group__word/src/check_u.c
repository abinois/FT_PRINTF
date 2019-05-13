/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:37 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 12:17:15 by edillenb         ###   ########.fr       */
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

char		*fill_str_u(t_flag flagz, ULL nb, size_t lmax, char *llutoa)
{
	char	*res;
	size_t	l_nb;
	size_t	len;
	size_t	c;

	len = ft_strlen(llutoa);
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
		res = put_toa(llutoa, res, &c);
		if (flagz.field > flagz.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (flagz.zer == true && flagz.dot == false)
	{
		if (flagz.field > l_nb)
			while (l_nb++ < flagz.field)
				res[c++] = '0';
		res = put_toa(llutoa, res, &c);
	}
	else
	{
		if (flagz.field > l_nb && flagz.field > flagz.preci)
			while (c < flagz.field - (flagz.preci > l_nb ? flagz.preci : l_nb))
				res[c++] = ' ';
		if (flagz.plus == true || flagz.sp == true)
			c--;
		if (flagz.preci > l_nb)
			while (l_nb++ < flagz.preci)
				res[c++] = '0';
		res = put_toa(llutoa, res, &c);
	}
	return (res);
}

/*
** MODIFIED
*/ 

ULL	check_u_flagz(t_flag flagz, va_list ap)
{
	ULL	number;

	if (flagz.l == true)
		return ((number = va_arg(ap, unsigned long)));
	if (flagz.ll == true)
		return ((number = va_arg(ap, ULL)));
	if (flagz.h == true)
		return ((number = (unsigned short)va_arg(ap, unsigned int)));
	if (flagz.hh == true)
		return ((number = (unsigned char)va_arg(ap, unsigned int)));
	return ((number = va_arg(ap, unsigned int)));
}

/*
** MODIFIED
*/

char		*malloc_str_u(t_flag flagz, va_list ap)
{
	long long	nb;
	char		*llutoa;
	char		*result;
	size_t		lmax;

	nb = check_u_flagz(flagz, ap);
	llutoa = ft_llutoa(nb);
	lmax = ft_strlen(llutoa);
	if (flagz.field > lmax)
		lmax = flagz.field;
	if (flagz.preci >= flagz.field && flagz.preci > lmax)
		lmax = flagz.preci;
	return ((result = fill_str_u(flagz, nb, lmax, llutoa)));
}
