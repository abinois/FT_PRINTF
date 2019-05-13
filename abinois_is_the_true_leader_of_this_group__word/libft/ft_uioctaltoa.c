/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uioctaltoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:46:14 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 14:49:43 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_uioctaltoa(unsigned int nbr)
{
	unsigned int		res;
	char				*tab;
	int					n;

	res = nbr;
	n = 1;
	while (res > 7)
	{
		n++;
		res /= 8;
	}
	if (!(tab = (char*)malloc(sizeof(*tab) * n + 1)))
		return (NULL);
	tab[n] = '\0';
	while (n-- > 0)
	{
		tab[n] = nbr % 8 + '0';
		nbr /= 8;
	}
	return (tab);
}
