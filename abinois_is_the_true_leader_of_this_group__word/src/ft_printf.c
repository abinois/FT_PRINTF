/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:14:02 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/30 18:59:15 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		flagz;
	int			m;
	int			i;
	char		*buf;
	char		*arg;

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
				if (!(arg = check_all(fmt, &F, &i, ap)))
					return (-1);
				if (!(buf = arg_to_buf(&buf, &arg)))
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
	ft_memdel((void**)&buf);
	return (1);
}
