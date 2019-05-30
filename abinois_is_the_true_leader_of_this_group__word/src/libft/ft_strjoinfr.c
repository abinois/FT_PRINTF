/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:58:59 by abinois           #+#    #+#             */
/*   Updated: 2019/05/30 16:04:30 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char	*to_free_or_not_to_free(char **s1, char **s2, char option)
{
	if (option == 1)
		ft_memdel((void**)s1);
	if (option == 2)
		ft_memdel((void**)s2);
	if (option == 3)
	{
		ft_memdel((void**)s1);
		ft_memdel((void**)s2);
	}
	return (NULL);
}

char	*ft_strjoinfr(char **s1, char **s2, char option)
{
	char	*new;
	size_t	len;
	int		i;

	if (!(*s1) || !(*s2))
		return (NULL);
	len = ft_strlen(*s1) + ft_strlen(*s2);
	if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
		return (to_free_or_not_to_free(s1, s2, option));
	i = -1;
	while ((*s1)[++i])
		new[i] = (*s1)[i];
	len = 0;
	while ((*s2)[len])
		new[i++] = (*s2)[len++];
	new[i] = '\0';
	to_free_or_not_to_free(s1, s2, option);
	return (new);
}
