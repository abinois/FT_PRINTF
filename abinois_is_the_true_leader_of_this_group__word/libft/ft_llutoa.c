/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:59:28 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 14:37:52 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_llutoa(unsigned long long nbr)
{
	unsigned long long	res;
	char				*tab;
	int					n;

	res = nbr;
	n = 1;
	while (res > 9)
	{
		n++;
		res /= 10;
	}
	if (!(tab = (char*)malloc(sizeof(*tab) * n + 1)))
		return (NULL);
	tab[n] = '\0';
	while (n-- > 0)
	{
		tab[n] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (tab);
}
