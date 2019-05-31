/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:46:22 by abinois           #+#    #+#             */
/*   Updated: 2019/05/31 11:16:41 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

char	*str_times_two(char **str)
{
	int		i;
	int		x;
	char	*new;
	char	ret;

	i = ft_strlen(*str);
	ret = 0;
	x = (*str)[0] - '0' >= 5 ? i-- + 1 : i--;
	if (!(new = (char*)malloc(sizeof(char) * x + 1)))
	{
		ft_memdel((void**)str);
		return (NULL);
	}
	new[x] = '\0';
	new[0] = '1';
	while (i >= 0 && --x >= 0)
	{
		if ((new[x] = ((*str)[i--] - '0') * 2 + ret) > 9)
		{
			ret = 1;
			new[x] -= 10;
		}
		else
			ret = 0;
		new[x] += '0';
	}
	ft_memdel((void**)str);
	return (new);
}

char	*str_by_two(char **str)
{
	char	*new;
	int		deci;
	int		ret;
	char	*final;
	int		i;

	new = "0";
	if (!(new = ft_strjoinfr(str, &new, 1)))
		return (NULL);
	if (!(final = (char*)malloc(sizeof(char) * (ft_strlen(new) + 1))))
	{
		ft_memdel((void**)str);
		ft_memdel((void**)&new);
		return (NULL);
	}
	ret = 0;
	i = -1;
	while (new[++i])
	{
		deci = (new[i] - '0') / 2 + ret;
		final[i] = deci + '0';
		ret = ((new[i] - '0') * 5) % 10;
	}
	final[i] = '\0';
	ft_memdel((void**)str);
	ft_memdel((void**)&new);
	return (final);
}

char	*get_mantissa(long double dbl)
{
	uint8_t	*nb;
	char	*binary;
	int		i;
	size_t	size;
	uint8_t	mask;

	nb = (uint8_t*)&dbl;
	i = 0;
	size = 65;
	if (!(binary = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	binary[--size] = '\0';
	while (i < 8)
	{
		mask = 1;
		while (mask)
		{
			binary[--size] = mask & *nb ? 1 + '0' : 0 + '0';
			mask <<= 1;
		}
		i++;
		nb++;
	}
	return (binary);
}

int16_t	get_exponent(long double dbl)
{
	int16_t	mask;
	int16_t	*nb;

	mask = 32767;
	nb = (int16_t*)&dbl;
	nb += 4;
	*nb &= mask;
	*nb -= 16383;
	return (*nb);
}
