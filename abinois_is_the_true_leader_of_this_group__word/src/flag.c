/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:16:20 by abinois           #+#    #+#             */
/*   Updated: 2019/05/10 10:12:38 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdbool.h>

void	check_first_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == '0')
		flagz->zer = true;
	else if (fmt[*i] == '-')
	{
		flagz->minus = true;
		flagz->zer = false;
	}
	else if (fmt[*i] == ' ')
		flagz->sp = true;
	else if (fmt[*i] == '+')
	{
		flagz->plus = true;
		flagz->sp = false;
	}
	else if (fmt[*i] == '#')
		flagz->hash = true;
	(*i)++;
}

void	check_l_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'L')
	{
		flagz->L = true;
		(*i)++;
	}
	else if (fmt[*i] == 'l')
	{
		flagz->l = true;
		(*i)++;
		if (fmt[*i] == 'l')
		{
			flagz->l = false;
			flagz->ll = true;
			(*i)++;
		}
	}
}

void	check_h_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'h')
	{
		flagz->h = true;
		(*i)++;
		if (fmt[*i] == 'h')
		{
			flagz->h = false;
			flagz->hh = true;
			(*i)++;
		}
	}
}

void	check_field_and_dot_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		flagz->field = ft_atoi(fmt + *i);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			(*i)++;
	}
	if (fmt[*i] == '.')
	{
		flagz->dot = true;
		(*i)++;
		if (fmt[*i] >= '0' && fmt[*i] <= '9')
		{
			flagz->preci = ft_atoi(fmt + *i);
			while (fmt[*i] >= '0' && fmt[*i] <= '9')
				(*i)++;
		}
	}
}

char	*check_all(const char *fmt, t_flag *flagz, int *i, va_list ap)
{
	reset_flagz(flagz);
	while ((fmt[*i] == '0' || fmt[*i] == '-' || fmt[*i] == ' ' || fmt[*i] == '+'
		|| fmt[*i] == '#') && fmt[*i])
		check_first_flagz(fmt, flagz, i);
	check_field_and_dot_flagz(fmt, flagz, i);
	check_l_flagz(fmt, flagz, i);
	check_h_flagz(fmt, flagz, i);
	return (check_conv1(fmt, *flagz, i, ap));
}
