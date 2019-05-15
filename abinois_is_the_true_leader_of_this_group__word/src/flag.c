/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:16:20 by abinois           #+#    #+#             */
/*   Updated: 2019/05/15 10:31:31 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdbool.h>

void	check_first_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == '0')
		F->zer = true;
	else if (fmt[*i] == '-')
	{
		F->minus = true;
		F->zer = false;
	}
	else if (fmt[*i] == ' ')
		F->sp = true;
	else if (fmt[*i] == '+')
	{
		F->plus = true;
		F->sp = false;
	}
	else if (fmt[*i] == '#')
		F->hash = true;
	(*i)++;
}

void	check_l_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'L')
	{
		F->bigl = true;
		(*i)++;
	}
	else if (fmt[*i] == 'l')
	{
		F->l = true;
		(*i)++;
		if (fmt[*i] == 'l')
		{
			F->l = false;
			F->ll = true;
			(*i)++;
		}
	}
}

void	check_h_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'h')
	{
		F->h = true;
		(*i)++;
		if (fmt[*i] == 'h')
		{
			F->h = false;
			F->hh = true;
			(*i)++;
		}
	}
}

void	check_field_dot_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		F->field = ft_atoi(fmt + *i);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			(*i)++;
	}
	if (fmt[*i] == '.')
	{
		F->dot = true;
		(*i)++;
		if (fmt[*i] >= '0' && fmt[*i] <= '9')
		{
			F->preci = ft_atoi(fmt + *i);
			while (fmt[*i] >= '0' && fmt[*i] <= '9')
				(*i)++;
		}
	}
}

char	*check_all(const char *fmt, t_flag *flagz, int *i, va_list ap)
{
	reset_flagz(F);
	while ((fmt[*i] == '0' || fmt[*i] == '-' || fmt[*i] == ' ' || fmt[*i] == '+'
		|| fmt[*i] == '#') && fmt[*i])
		check_first_flagz(fmt, F, i);
	check_field_dot_flagz(fmt, F, i);
	check_l_flagz(fmt, F, i);
	check_h_flagz(fmt, F, i);
	return (check_conv1(fmt, *F, i, ap));
}
