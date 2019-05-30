/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:37:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/30 18:55:04 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

char	*m_to_buf(int *m, char *buf, const char *fmt, int i)
{
	char	*tmpsub;
	char	*tmpjoin;

	if (!buf && !(buf = ft_strnew(0)))
		return (NULL);
	if (!(tmpsub = ft_strsub(fmt, i - *m, *m)))
	{
		ft_memdel((void**)&buf);
		return (NULL);
	}
	if (!(tmpjoin = ft_strjoinfr(&buf, &tmpsub, 3)))
		return (NULL);
	*m = 0;
	return (tmpjoin);
}

char	*percent_to_buf(int *m, char *buf, int *i)
{
	char	*percent;
	char	*tmpjoin;

	percent = "%";
	if (!buf && !(buf = ft_strnew(0)))
		return (NULL);
	if (!(tmpjoin = ft_strjoinfr(&buf, &percent, 1)))
		return (NULL);
	*m = -1;
	(*i)++;
	return (tmpjoin);
}

int		m_or_percent(int *m, char **buf, const char *fmt, int *i)
{
	if (*m)
		if (!(*buf = m_to_buf(m, *buf, fmt, *i - 1)))
			return (-1);
	if (fmt[*i] == '%')
	{
		if (!(*buf = percent_to_buf(m, *buf, i)))
			return (-1);
		return (1);
	}
	return (0);
}

char	*arg_to_buf(char **buf, char **arg)
{
	char	*tmpjoin;

	if (!(*buf) && (!(*buf = ft_strnew(0))))
	{
		ft_memdel((void**)arg);
			return (NULL);
	}
	if (!(tmpjoin = ft_strjoinfr(buf, arg, 3)))
		return (NULL);
	return (tmpjoin);
}
