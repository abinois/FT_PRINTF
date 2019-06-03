/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:28:27 by abinois           #+#    #+#             */
/*   Updated: 2019/06/03 10:25:07 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

char	*put_sp(t_flag flagz, size_t *c, size_t lmax, char *res)
{
	if (F.field > F.preci)
		while (*c < lmax)
			res[(*c)++] = ' ';
	return (res);
}

char	*reput_backzer(char **str)
{
	size_t	i;

	i = -1;
	while ((*str)[++i])
		if ((*str)[i] == -1)
			(*str)[i] = 0;
	return (*str);
}

int		print__return(va_list ap, char **buf)
{
	int		rv;
	int		x;

	rv = return_value(*buf);
	x = ft_strlen(*buf);
	reput_backzer(buf);
	put_color_printf(*buf, x);
	printf("bangbang\n");
	ft_memdel((void**)buf);
	va_end(ap);
	return (rv);
}
