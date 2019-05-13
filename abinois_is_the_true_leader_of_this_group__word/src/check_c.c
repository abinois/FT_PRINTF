/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:00:17 by abinois           #+#    #+#             */
/*   Updated: 2019/05/13 19:33:07 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

char	*malloc_str_c(t_flag flagz, va_list ap)
{
	char	c;
	size_t 	lmax;
	char	*res;
	size_t	i;

	c = (char)va_arg(ap, UI);
	i = 0;
	lmax = flagz.field > 1 ? flagz.field : 1;
	if (!(res = (char *)malloc(sizeof(char) * (lmax + 1))))
		return (NULL);
	res[lmax] = '\0';
	if (flagz.minus)
	{
		res[i++] = c;
		while (i < flagz.field)
			res[i++] = ' ';
	}
	else
	{
		while (flagz.field > 1 && i < flagz.field - 1)
			res[i++] = (flagz.zer ? '0' : ' ');
		res[i] = c;
	}
	return (res);
}
