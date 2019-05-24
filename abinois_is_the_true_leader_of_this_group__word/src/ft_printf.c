/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:15:31 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/23 12:12:43 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
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
			if (m_or_percent(&m, &buf, fmt, &i) == -1)
				return (-1);
			if (m == 0)
			{
				if (!(buf = arg_to_buf(check_all(fmt, &F, &i, ap), &buf)))
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
	free(buf);
	return (1);
}

int		main(int argc, char **argv)
{

	long double	a = 5674736738768371468418381.0;
	(void)argc;
	(void)argv;
	ft_putstr("_____ ft_printf _____\n");
	ft_printf("%Lf\n", a);
	ft_putstr("_____ printf _____\n");
	printf("%Lf\n", a);
	return (0);
}
