/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:16:20 by abinois           #+#    #+#             */
/*   Updated: 2019/05/08 20:02:16 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdbool.h>

void	check_first_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == '0' && fmt[*i])
		flagz->zer = true;
	else if (fmt[*i] == '-')
	{
		flagz->minus = true;
		flagz->zer = false;
	}
	else if (fmt[*i] == ' ' && fmt[*i])
		flagz->sp = true;
	else if (fmt[*i] == '+')
	{
		flagz->plus = true;
		flagz->sp = false;
	}
	else if (fmt[*i] == '#' && fmt[*i])
		flagz->hash = true;
	*i++;
}

void	check_l_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'L' && fmt[*i])
	{
		flagz->L = true;
		*i++;
	}
	else if (fmt[*i] == 'l' && fmt[*i])
	{
		flagz->l = true;
		*i++;
		if (fmt[*i] == 'l' && fmt[*i])
		{
			flagz->l = false;
			flagz->ll = true;
			*i++;
		}
	}
}

void	check_h_flagz(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == 'h' && fmt[*i])
	{
		flagz->h = true;
		*i++;
		if (fmt[*i] == 'h' && fmt[*i])
		{
			flagz->h = false;
			flagz->hh = true;
			*i++;
		}
	}
}

void	check_dot_flag(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] == '.' && fmt[*i])
	{
		flagz->dot = true;
		*i++;
		if (fmt[*i] >= '0' && fmt[*i] <= 9 && fmt[*i])
		{
			flagz->preci = ft_atoi(fmt + i);
			while (fmt[*i] >= '0' && fmt[*i] <= '9' && fmt[*i])
				*i++;
		}
	}
}

void	check_preci_flag(const char *fmt, t_flag *flagz, int *i)
{
	if (fmt[*i] >= '0' && fmt[*i] <= '9' && fmt[*i])
	{
		flagz->field = ft_atoi(fmt + i);
		while (fmt[*i] >= '0' && fmt[*i] <= '9' && fmt[*i])
			*i++;
	}
}
