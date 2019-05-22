/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:04:41 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/22 17:58:29 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../abinois_is_the_true_leader_of_this_group__word/libft/libft.h"

char	*ldbltobinary(long double dbl)
{
	uint8_t		*nb;
	char		*binary;
	int			i;
	size_t		size;
	uint8_t		mask;

	nb = (uint8_t*)&dbl;
	i = 0;
	size = 81;
	if (!(binary = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	binary[--size] = '\0';
	while (i < 10)
	{
		mask = 1;
		while (mask <= 128)
		{
			binary[--size] = mask & *nb ? 1 + '0' : 0 + '0';
			mask = mask << 1;
		}
		i++;
		nb++;
	}
	return (binary);
}

int		main(void)
{
//	long double	dbl;
//	char	*result;

	printf("yes");
//	dbl = -0.51;
//	result = ldbltobinary(dbl);
	return (0);
}
