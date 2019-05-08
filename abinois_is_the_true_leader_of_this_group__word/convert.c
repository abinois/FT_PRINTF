/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:29 by abinois           #+#    #+#             */
/*   Updated: 2019/05/08 19:08:50 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_printf.h"

int		check_conv1(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'f')
	{
		flagz->f = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'd')
	{
		flagz->d = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'i')
	{
		flagz->i = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'o')
	{
		flagz->o = true;
		(*i)++;
		return (1);
	}
	return (check_conv2(fmt, flagz, i));
}

int		check_conv2(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'u')
	{
		flagz->u = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'x')
	{
		flagz->x = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'X')
	{
		flagz->X = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'c')
	{
		flagz->c = true;
		(*i)++;
		return (1);
	}
	return (check_conv3(fmt, flagz, i));
}

int		check_conv3(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 's')
	{
		flagz->s = true;
		(*i)++;
		return (1);
	}
	else if (fmt[*i] == 'p')
	{
		flagz->p = true;
		(*i)++;
		return (1);
	}
	return (0);
}
