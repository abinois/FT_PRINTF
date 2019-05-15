/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/15 18:00:54 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** will malloc a new string if input is of type d or i
*/

char		*fill_str(t_flag flagz, long long nb, size_t lmax, char *lltoa)
{
	char	*res;
	size_t	l_nb;
	size_t	len;
	size_t	c;

	len = ft_strlen(lltoa);
	l_nb = nb >= 0 ? len : len - 1;
	lltoa += nb < 0 ? 1 : 0;
	c = 0;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	if (F.minus)
	{
		res = put_sign(F, nb, res, &c);
		res = put_toa(lltoa, put_zer(F.preci, res, &c, l_nb), &c);
		if (F.field > F.preci)
			while (c < lmax)
				res[c++] = ' ';
	}
	else if (F.zer && !(F.dot))
	{
		res = put_sign(F, nb, res, &c);
		if (c == 1)
			F.field--;
		res = put_toa(lltoa, put_zer(F.preci, res, &c, l_nb), &c);
	}
	else
	{
		if (F.field > l_nb && F.field > F.preci)
			while (c < F.field - (F.preci > l_nb ? F.preci : l_nb))
				res[c++] = ' ';
		res = put_sign(F, nb, res, &c);
		res = put_toa(lltoa, put_zer(F.preci, res, &c, l_nb), &c);
	}
	return (res);
}

char		*malloc_str_d_i(t_flag flagz, va_list ap)
{
	long long	nb;
	char		*lltoa;
	char		*result;
	size_t		len;

	nb = check_d_i_flagz(flagz, ap);
	lltoa = ft_lltoa(nb);
	len = ft_strlen(lltoa);
	if (F.field > len)
		len = F.field;
	if (F.preci >= F.field && F.preci > len)
		len = nb < 0 ? F.preci + 1 : F.preci;
	if (nb > 0 && (F.plus || F.sp) && F.field < len)
		len++;
	return ((result = fill_str(F, nb, len, lltoa)));
}
