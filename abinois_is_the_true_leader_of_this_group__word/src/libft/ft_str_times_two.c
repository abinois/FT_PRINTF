/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_times_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:56:07 by abinois           #+#    #+#             */
/*   Updated: 2019/05/28 12:01:28 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_times_two(char *str)
{
	int		i;
	int		x;
	char	*new;
	char	ret;

	i = ft_strlen(str);
	ret = 0;
	x = str[0] - '0' >= 5 ? i-- + 1 : i--;
	if (!(new = (char*)malloc(sizeof(char) * x + 1)))
		return (NULL);
	new[x] = '\0';
	new[0] = '1';
	while (i >= 0 && --x >= 0)
	{
		if ((new[x] = (str[i--] - '0') * 2 + ret) > 9)
		{
			ret = 1;
			new[x] -= 10;
		}
		else
			ret = 0;
		new[x] += '0';
	}
	ft_memdel((void**)&str);
	return (new);
}
