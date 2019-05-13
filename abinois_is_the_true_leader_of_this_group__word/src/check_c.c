/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:00:17 by abinois           #+#    #+#             */
/*   Updated: 2019/05/13 20:13:23 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

char	*malloc_str_c(t_flag F, va_list ap)
{
	char	c;
	size_t 	lmax;
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
