/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:59:33 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/13 20:05:12 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_hexatoa(unsigned int nbr)
{
	char				*base;
	unsigned int		res;
	char				*tab;
	int					n;

	base = "0123456789abcdef";
	res = nbr;
	n = 1;
	while (res > 15)
	{
		n++;
		res /= 16;
	}
	if (!(tab = (char*)malloc(sizeof(*tab) * n + 1)))
		return (NULL);
	tab[n] = '\0';
	while (n-- > 0)
	{
		tab[n] = base [nbr % 16];
		nbr /= 16;
	}
	return (tab);
}
