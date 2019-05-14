/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:29 by abinois           #+#    #+#             */
/*   Updated: 2019/05/14 15:34:52 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*check_conv1(const char *fmt, t_flag F, int *i, va_list ap)
{
	if (fmt[*i] == 'f')
	{
		// > fonction check_f_flags + va_arg double
		(*i)++;
		return (NULL);
	}
	else if (fmt[*i] == 'd' || fmt[*i] == 'i')
	{
		(*i)++;
		return (malloc_str_d_i(F, ap));
	}
	else if (fmt[*i] == 'o')
	{
		(*i)++;
		return (malloc_str_o(F, ap));
	}
	return (check_conv2(fmt, F, i, ap));
}

char	*check_conv2(const char *fmt, t_flag F, int *i, va_list ap)
{
	if (fmt[*i] == 'u')
	{
		(*i)++;
		return (malloc_str_u(F, ap));
	}
	else if (fmt[*i] == 'x')
	{
		(*i)++;
		return (malloc_str_xX(F, ap));
	}
	else if (fmt[*i] == 'X')
	{
		(*i)++;
		return (ft_str_up(malloc_str_xX(F, ap)));
	}
	return (check_conv3(fmt, F, i, ap));
}

char	*check_conv3(const char *fmt, t_flag F, int *i, va_list ap)
{
	if (fmt[*i] == 's')
	{
		// > fonction check_s_flags + va_arg char *
		(*i)++;
		return (NULL);
	}
	else if (fmt[*i] == 'p')
	{
		F.hash = true;
		(*i)++;
		return (malloc_str_p(F, ap));
	}
	else if (fmt[*i] == 'c')
	{
		(*i)++;
		return (malloc_str_c(F, ap));
	}
	return (NULL);
}
