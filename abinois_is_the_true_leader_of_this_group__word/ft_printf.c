/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:15:31 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 15:42:28 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

/*
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
			if (m_or_percent_to_buf(&m, buf, fmt, &i) == -1)
				return (-1);
			if (m == 0)
				check_them_all(fmt, &flagz, &i, ap);
			else
				m = 0;
		else
			m++;
	if (!(buf = m_to_buf(&m, buf, fmt, i)))
		return (-1);
	ft_putendl(buf);
	return (1);
}
*/

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char				*str = "lol";
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
	long	adress;

	adress = (long)&str;
//	ft_printf("Bonjour monsieur%% le commissaire.");
	printf("%p\n", str);
	printf("%ld\n", adress);
	return (0);
}
