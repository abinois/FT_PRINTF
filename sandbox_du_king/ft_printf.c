/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:15:31 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/07 15:16:41 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *fmt, ...)
{
	va_list 	ap;
	va_list		copy;
	
	va_start(ap, fmt);
	va_copy(copy, ap);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '%')
				ft_putchar('%');
			else if (*fmt == 'd')
				ft_putnbr(va_arg(ap, int));
			else if (*fmt == 's')
				ft_putstr(va_arg(ap, char *));
			else if (*fmt == 'c')
				ft_putchar(va_arg(ap, int));
			else
			{
				ft_putstr("error");
				return (-1);
			}
			fmt++;
		}
		else
		{
			ft_putchar(*fmt);
			fmt++;
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	double number;

	number = 2;
	ft_printf("Tu as un %s %s. et tu as %s ans.\n", "petit", "penis", 30);
	//printf("Tu as un %s %s. Et tu as %d ans.\n", "petit", 30, "penis");
	return (0);
}
