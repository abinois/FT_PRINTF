/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:37:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/10 21:00:37 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

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
	if (!(tmpjoin = ft_strjoin(buf, tmpsub)))
	{
		ft_memdel((void**)&buf);
		ft_memdel((void**)&tmpsub);
		return (NULL);
	}
	ft_memdel((void**)&buf);
	ft_memdel((void**)&tmpsub);
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
	if (!(tmpjoin = ft_strjoin(buf, percent)))
	{
		ft_memdel((void**)&buf);
		return (NULL);
	}
	ft_memdel((void**)&buf);
	*m = -1;
	(*i)++;
	return (tmpjoin);
}

int		m_or_percent_to_buf(int *m, char **buf, const char *fmt, int *i)
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

char	*arg_to_buf(char *arg, char **buf)
{
	char	*tmpjoin;

	if (!(*buf) && !(*buf = ft_strnew(0)))
		return (NULL);
	if (!(tmpjoin = ft_strjoin(*buf, arg)))
	{
		ft_memdel((void**)buf);
		return (NULL);
	}
	ft_memdel((void**)&arg);
	ft_memdel((void**)buf);
	return (tmpjoin);
}
