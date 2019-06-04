/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:28:27 by abinois           #+#    #+#             */
/*   Updated: 2019/06/04 14:45:16 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include "libft/libft.h"

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

char		*p_toa(char *toa, char *res, size_t *c, t_flag flagz)
{
	size_t	i;

	i = *toa == '-' ? 1 : 0;
	if (toa[0] == '0' && toa[1] == 0 && ((F.dot && F.preci == 0
		&& F.conv != 'p') || (F.hash && F.conv == 'o')))
		return (res);
	while (toa[i])
		res[(*c)++] = toa[i++];
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
	if (!(F->minus) && F->zer && !(F->dot) && *c == 1 && F->field > 0)
		F->field--;
	return (res);
}

char		*p_zer(size_t flag, char *res, size_t *c, size_t l_nb)
{
	if (flag > l_nb)
	{
		while (l_nb++ < flag)
			res[(*c)++] = '0';
	}
	return (res);
}

char		*put_hash(char *res, size_t *c, t_flag flagz, size_t l_nb)
{
	p_zer(F.preci, res, c, l_nb);
	if (F.conv == 'o')
	{
		if (F.hash && *c == 0)
			res[(*c)++] = '0';
		else if (F.hash)
			res[(*c) - 1] = '0';
	}
	return (res);
}
