/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:37:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/08 18:58:55 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

char	*m_to_buf(int *m, char *buf, const char *fmt, int i)
{
	char	*tmpsub;
	char	*tmpjoin;

	if (!buf && !(buf = ft_strnew(0)))
		return (NULL);
	if (!(tmpsub = ft_strsub(fmt, i - *m, *m)))
		return (NULL);
	if (!(tmpjoin = ft_strjoin(buf, tmpsub)))
		return (NULL);
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
		return (NULL);
	ft_memdel((void**)&buf);
	*m = 0;
	(*i)++;
	return (tmpjoin);
}
