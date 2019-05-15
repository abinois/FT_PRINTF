/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:28:27 by abinois           #+#    #+#             */
/*   Updated: 2019/05/15 18:01:41 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>

void		reset_flagz(t_flag *flagz)
{
	flagz->zer = false;
	flagz->minus = false;
	flagz->sp = false;
	flagz->plus = false;
	flagz->hash = false;
	flagz->field = 0;
	flagz->dot = false;
	flagz->preci = 0;
	flagz->l = false;
	flagz->ll = false;
	flagz->bigl = false;
	flagz->h = false;
	flagz->hh = false;
	flagz->conv = 'r';
}

char		*put_toa(char *toa, char *res, size_t *c)
{
	while (*toa)
		res[(*c)++] = *toa++;
	return (res);
}

char		*put_sign(t_flag flagz, long long nb, char *res, size_t *c)
{
	if (!(F.minus) && (!(F.zer) || F.dot) && ((nb < 0 || F.plus || F.sp)
			&& *c != 0))
		(*c)--;
	if (nb < 0)
		res[(*c)++] = '-';
	else if (F.plus && nb >= 0)
		res[(*c)++] = '+';
	else if (F.sp && nb >= 0)
		res[(*c)++] = ' ';
	return (res);
}

char		*put_zer(size_t flag, char *res, size_t *c, size_t l_nb)
{
	if (flag > l_nb)
		while (l_nb++ < flag)
			res[(*c)++] = '0';
	return (res);
}

char		*llhexatoa(ULL nbr)
{
	char				*base;
	ULL					res;
	char				*tab;
	int					n;

	base = "0123456789abcdef";
	res = nbr;
	n = 1;
	while (res > 15)
	{
		n++;
		res /= 16;
	}
	if (!(tab = (char*)malloc(sizeof(*tab) * n + 1)))
		return (NULL);
	tab[n] = '\0';
	while (n-- > 0)
	{
		tab[n] = base[nbr % 16];
		nbr /= 16;
	}
	return (tab);
}
