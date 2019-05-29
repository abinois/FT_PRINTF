/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:58:59 by abinois           #+#    #+#             */
/*   Updated: 2019/05/29 18:49:18 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinfr(const char *s1, const char *s2, char option)
{
	char	*new;
	size_t	len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
	{
		((option == 1) || (option == 3)) ? ft_memdel((void**)&s1) : 0;
		((option == 2) || (option == 3)) ? ft_memdel((void**)&s2) : 0;
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	len = 0;
	while (s2[len])
		new[i++] = s2[len++];
	new[i] = '\0';
	((option == 1) || (option == 3)) ? ft_memdel((void**)&s1) : 0;
	((option == 2) || (option == 3)) ? ft_memdel((void**)&s2) : 0;
	return (new);
}
