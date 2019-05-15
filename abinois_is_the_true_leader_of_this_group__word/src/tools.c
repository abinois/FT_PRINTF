/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:28:27 by abinois           #+#    #+#             */
/*   Updated: 2019/05/15 19:25:43 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../libft/libft.h"

void		reset_flagz(t_flag *flagz)
{
	F->zer = false;
	F->minus = false;
	F->sp = false;
	F->plus = false;
	F->hash = false;
	F->field = 0;
	F->dot = false;
	F->preci = 0;
	F->l = false;
	F->ll = false;
	F->bigl = false;
	F->h = false;
	F->hh = false;
	F->conv = 'r';
	F->nb = 0;
}

char		*p_toa(char *toa, char *res, size_t *c)
{
	while (*toa)
		res[(*c)++] = *toa++;
	return (res);
}

char		*p_sign(t_flag *flagz, char *res, size_t *c)
{
	if (!(F->minus) && (!(F->zer) || F->dot) && ((F->nb < 0 || F->plus || F->sp)
			&& *c != 0))
		(*c)--;
	if (F->nb < 0)
		res[(*c)++] = '-';
	else if (F->plus && F->nb >= 0)
		res[(*c)++] = '+';
	else if (F->sp && F->nb >= 0)
		res[(*c)++] = ' ';
	if (!(F->minus) && F->zer && !(F->dot) && *c == 1)
		F->field--;
	return (res);
}

char		*p_zer(size_t flag, char *res, size_t *c, size_t l_nb)
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
