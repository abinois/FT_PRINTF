/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:28:27 by abinois           #+#    #+#             */
/*   Updated: 2019/05/08 18:30:41 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdbool.h>

void	reset_flagz(t_flag *flagz)
{
	flagz->zer = false;
	flagz->minus = false;
	flagz->sp = false;
	flagz->plus = false;
	flagz->hash = false;
	flagz->field = 0;
	flagz->dot = false;
	flagz->preci = 0;
	flagz->l = false;
	flagz->ll = false;
	flagz->L = false;
	flagz->h = false;
	flagz->hh = false;
	flagz->f = false;
	flagz->d = false;
	flagz->i = false;
	flagz->o = false;
	flagz->u = false;
	flagz->x = false;
	flagz->X = false;
	flagz->c = false;
	flagz->s = false;
	flagz->p = false;
}

void	print_flagz(t_flag *flagz)
{
	ft_putstr("zer = ");
	ft_putnbr(flagz->zer);
	ft_putchar('\n');
	ft_putstr("minus = ");
	ft_putnbr(flagz->minus);
	ft_putchar('\n');
	ft_putstr("sp = ");
	ft_putnbr(flagz->sp);
	ft_putchar('\n');
	ft_putstr("plus = ");
	ft_putnbr(flagz->plus);
	ft_putchar('\n');
	ft_putstr("hash = ");
	ft_putnbr(flagz->hash);
	ft_putchar('\n');
	ft_putstr("field = ");
	ft_putnbr(flagz->field);
	ft_putchar('\n');
	ft_putstr("dot = ");
	ft_putnbr(flagz->dot);
	ft_putchar('\n');
	ft_putstr("preci = ");
	ft_putnbr(flagz->preci);
	ft_putchar('\n');
	ft_putstr("l = ");
	ft_putnbr(flagz->l);
	ft_putchar('\n');
	ft_putstr("ll = ");
	ft_putnbr(flagz->ll);
	ft_putchar('\n');
	ft_putstr("L = ");
	ft_putnbr(flagz->L);
	ft_putchar('\n');
	ft_putstr("h = ");
	ft_putnbr(flagz->h);
	ft_putchar('\n');
	ft_putstr("hh = ");
	ft_putnbr(flagz->hh);
	ft_putchar('\n');
	ft_putstr("f = ");
	ft_putnbr(flagz->f);
	ft_putchar('\n');
	ft_putstr("d = ");
	ft_putnbr(flagz->d);
	ft_putchar('\n');
	ft_putstr("i = ");
	ft_putnbr(flagz->i);
	ft_putchar('\n');
	ft_putstr("o = ");
	ft_putnbr(flagz->o);
	ft_putchar('\n');
	ft_putstr("u = ");
	ft_putnbr(flagz->u);
	ft_putchar('\n');
	ft_putstr("x = ");
	ft_putnbr(flagz->x);
	ft_putchar('\n');
	ft_putstr("X = ");
	ft_putnbr(flagz->X);
	ft_putchar('\n');
	ft_putstr("c = ");
	ft_putnbr(flagz->c);
	ft_putchar('\n');
	ft_putstr("s = ");
	ft_putnbr(flagz->s);
	ft_putchar('\n');
	ft_putstr("p = ");
	ft_putnbr(flagz->p);
	ft_putchar('\n');
}
