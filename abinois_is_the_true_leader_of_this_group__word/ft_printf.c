/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:15:31 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/08 19:09:17 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>


int		ft_printf(const char *fmt, ...)
{
	va_list 	ap;
	t_flag		flagz;
	int			m;
	int			i;
	char		*buf;

	i = 0;
	m = 0;
	buf = NULL;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i++] == '%')
		{
			if (m)
				if (!(buf = m_to_buf(&m, buf, fmt, i - 1)))
					return (-1);
			if (fmt[i] == '%')
			{
				if (!(buf = percent_to_buf(&m, buf, &i)))
					return (-1);
			}
			else
			{
				reset_flagz(&flagz);
				while ((fmt[i] == '0' || fmt[i] == '-' || fmt[i] == ' '
					|| fmt[i] == '+' || fmt[i] == '#') && fmt[i])
					check_first_flagz(fmt, &flagz, &i);
				check_preci_flag(fmt, &flagz, &i);
				check_dot_flag(fmt, &flagz, &i);
				check_l_flagz(fmt, &flagz, &i);
				check_h_flagz(fmt, &flagz, &i);
				check_conv1(fmt, &flagz, &i);
				print_flagz(&flagz);
			}
		}
		else
			m++;
	}
	if (!(buf = m_to_buf(&m, buf, fmt, i)))
		return (-1);
	return (1);
}


int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

//	char				*str = "lol";
//	char				c = 'a';
//	int					d = 10;
//	long				l = 2147483648;
//	long long			ll = 2147483648;
//	float				f = 4.5;
//	double				dou = 42.0;
//	long double			londou = 42.0;
//	unsigned int		ui = 10;
//	unsigned long		ul = 10;
//	unsigned long long	ull = 10;

	ft_printf("Bonjour monsieur%p le commissaire.");
//	printf("%7c\n", 0);
	return (0);
}
