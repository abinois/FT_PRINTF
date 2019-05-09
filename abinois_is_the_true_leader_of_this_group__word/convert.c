/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:29 by abinois           #+#    #+#             */
/*   Updated: 2019/05/09 11:53:18 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		check_conv1(const char *fmt, t_flag *flagz, int *i, va_list ap)
{
	if (fmt[*i] == 'f')
	{
		// > fonction check_f_flags + va_arg double
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'd' || fmt[*i] == 'i')
	{
		// > fonction check_d_flags + va_arg int
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'o')
	{
		// > fonction check_o_flags + va_arg unsigned int
		(*i)++;
		return (1);
	}
	return (check_conv2(fmt, flagz, i, ap));
}

int		check_conv2(const char *fmt, t_flag *flagz, int *i, va_list ap)
{
	if (fmt[*i] == 'u')
	{
		// > fonction check_u_flags + va_arg unsigned ...
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'x')
	{
		// > fonction check_x_flags + va_arg unsigned int 
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'X')
	{
		// > fonction check_X_flags + va_arg unsigned int
		(*i)++;
		return (1);
	}
	return (check_conv3(fmt, flagz, i, ap));
}

int		check_conv3(const char *fmt, t_flag *flagz, int *i, va_list ap)
{
	if (fmt[*i] == 's')
	{
		// > fonction check_s_flags + va_arg char *
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'p')
	{
		// > fonction check_p_flags + va_arg void *
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'c')
	{
		// > fonction check_c_flasgs + va_arg int
		(*i)++;
		return (1);
	}
	return (0);
}
