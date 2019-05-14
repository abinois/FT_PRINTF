/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:52:39 by abinois           #+#    #+#             */
/*   Updated: 2019/05/14 17:32:32 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char	*llhexatoa(ULL nbr)
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
		tab[n] = base [nbr % 16];
		nbr /= 16;
	}
	return (tab);
}

char	*malloc_str_p(t_flag F, va_list ap)
{
	ULL		nb;
	char	*toa;
	size_t	lmax;
	char	*res;

	nb = va_arg(ap, ULL);
	toa = llhexatoa(nb);
	lmax = ft_strlen(toa);
	if (F.field > lmax)
		lmax = F.field;
	if (F.preci >= F.field && F.preci > ft_strlen(toa))
		lmax = F.preci;
	lmax += 2;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	return ((res = fill_str_xX(F, lmax, toa, res)));
}
