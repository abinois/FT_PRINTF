/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:29 by abinois           #+#    #+#             */
/*   Updated: 2019/05/27 20:16:15 by edillenb         ###   ########.fr       */
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
	else if (fmt[*i] == 'o')
	{
		F.conv = 'o';
		(*i)++;
		return (malloc_str_ou(F, ap));
	}
	return (check_conv2(fmt, F, i, ap));
}

char		*check_conv2(const char *fmt, t_flag flagz, int *i, va_list ap)
{
	if (fmt[*i] == 'u')
	{
		F.conv = 'u';
		(*i)++;
		return (malloc_str_ou(F, ap));
	}
	else if (fmt[*i] == 'x')
	{
		F.conv = 'x';
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
	if (fmt[*i] == 's')
	{
		(*i)++;
		return (malloc_str_s(F, ap));
	}
	else if (fmt[*i] == 'p')
	{
		F.conv = 'p';
		F.hash = true;
		(*i)++;
		return (malloc_str_xp(F, ap));
	}
	else if (fmt[*i] == 'c')
	{
		(*i)++;
		return (malloc_str_c(F, ap));
	}
	return (NULL);
}

long long	check_d_i_flagz(t_flag flagz, va_list ap)
{
	long long	number;

	if (F.l)
		return ((number = va_arg(ap, long)));
	if (F.ll)
		return ((number = va_arg(ap, long long)));
	if (F.h)
		return ((number = (short)va_arg(ap, int)));
	if (F.hh)
		return ((number = (char)va_arg(ap, int)));
	return ((number = va_arg(ap, int)));
}

ULL			check_poux_flagz(t_flag flagz, va_list ap)
{
	ULL	number;

	if (F.conv == 'p')
		return ((number = va_arg(ap, ULL)));
	if (F.l)
		return ((number = va_arg(ap, unsigned long)));
	if (F.ll)
		return ((number = va_arg(ap, ULL)));
	if (F.h)
		return ((number = (unsigned short)va_arg(ap, UI)));
	if (F.hh)
		return ((number = (unsigned char)va_arg(ap, UI)));
	return ((number = va_arg(ap, UI)));
}
