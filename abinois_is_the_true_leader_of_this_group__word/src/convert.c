/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:29 by abinois           #+#    #+#             */
/*   Updated: 2019/06/03 10:22:29 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

char		*check_conv1(const char *fmt, t_flag flagz, int *i, va_list ap)
{
	if (fmt[*i] == 'f')
	{
		(*i)++;
		if (!F.dot)
			F.preci = 6;
		return (get_float(F, ap));
	}
	else if (fmt[*i] == 'd' || fmt[*i] == 'i')
	{
		(*i)++;
		return (malloc_str_d(F, ap));
	}
	else if (fmt[*i] == 'o' || fmt[*i] == 'u')
	{
		F.conv = fmt[*i];
		(*i)++;
		return (malloc_str_ou(F, ap));
	}
	else if (fmt[*i] == 's')
	{
		(*i)++;
		return (malloc_str_s(F, ap));
	}
	return (check_conv2(fmt, F, i, ap));
}

char		*check_conv2(const char *fmt, t_flag flagz, int *i, va_list ap)
{
	if (fmt[*i] == 'x' || fmt[*i] == 'p')
	{
		F.conv = fmt[*i];
		if (F.conv == 'p')
			F.hash = true;
		(*i)++;
		return (malloc_str_xp(F, ap));
	}
	else if (fmt[*i] == 'X')
	{
		F.conv = 'x';
		(*i)++;
		return (ft_str_up(malloc_str_xp(F, ap)));
	}
	return (check_conv3(fmt, F, i, ap));
}

char		*check_conv3(const char *fmt, t_flag flagz, int *i, va_list ap)
{
	char	option;

	option = 0;
	if (fmt[*i] == 'c' || fmt[*i] == '%')
	{
		option = fmt[*i] == '%' ? 1 : 0; 
		(*i)++;
		return (malloc_str_c(F, ap, option));
	}
	return (NULL);
}
