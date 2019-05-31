/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:59:14 by abinois           #+#    #+#             */
/*   Updated: 2019/05/31 18:59:34 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char **s, unsigned int strt, size_t len, int o)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!*s || !(new = ft_strnew(len)))
		return (NULL);
	while (len--)
		new[i++] = (*s)[strt++];
	if (o == 1)
		ft_memdel((void**)s);
	return (new);
}
