/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:14:02 by edillenb          #+#    #+#             */
/*   Updated: 2019/06/05 14:44:29 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	jgagnedeslignes(va_list ap, const char *fmt, int *im, char **buf)
{
	char	*arg;
	t_flag	flagz;

	while (fmt[im[0]])
		if (fmt[im[0]++] == '%')
		{
			if (m_or_percent(&(im[1]), buf, fmt, &(im[0])) == -1)
				return (-1);
			if (im[1] == 0)
			{
				if (!(arg = check_all(fmt, &F, &(im[0]), ap)))
					return (-1);
				if (!(*buf = arg_to_buf(buf, &arg)))
					return (-1);
			}
			else
				im[1] = 0;
		}
		else
			im[1]++;
	if (!(*buf = m_to_buf(&(im[1]), *buf, fmt, im[0])))
		return (-1);
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*buf;
	int		im[2];

	buf = NULL;
	im[0] = 0;
	im[1] = 0;
	g_fd = 1;
	va_start(ap, fmt);
	if (jgagnedeslignes(ap, fmt, im, &buf) == -1)
		return (-1);
	return (print_return(ap, &buf));
}
