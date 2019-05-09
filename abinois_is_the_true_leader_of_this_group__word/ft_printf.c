/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:15:31 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 23:04:10 by abinois          ###   ########.fr       */
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
		if (fmt[i++] == '%')
		{
			if (m_or_percent_to_buf(&m, buf, fmt, &i) == -1)
				return (-1);
			if (m == 0)
			{
				if (!(buf = arg_to_buf(check_all(fmt, &flagz, &i, ap), buf)))
					return (-1);
			}
			else
				m = 0;
		}
		else
			m++;
	if (!(buf = m_to_buf(&m, buf, fmt, i)))
		return (-1);
	ft_putstr(buf);
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
//	long	adress;
//	short				h = 5;

//	adress = (long)&str;
	ft_printf("%-10hhd\n", 127);
//	printf("%p\n", str);
	printf("%-10hhd\n", 127);
	return (0);
}
