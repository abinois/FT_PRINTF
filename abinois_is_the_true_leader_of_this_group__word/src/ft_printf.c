/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:14:02 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/29 19:27:36 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
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
