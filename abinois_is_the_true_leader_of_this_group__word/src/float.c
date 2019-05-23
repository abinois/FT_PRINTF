/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:46:22 by abinois           #+#    #+#             */
/*   Updated: 2019/05/23 15:57:53 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*allocplus(char *buf, char ret, int *x)
{
	int		i;
	int		j;
	char	*buf2;

	i = 0;
	j = 1;
	buf[(*x)] += '0';
	if (--(*x) < 0 && ret == 1)
	{
		while (buf[i])
			i++;
		if (!( buf2= (char*)malloc(sizeof(char) * ++i + 1)))
			return (NULL);
		buf2[i] = '\0';
		i = 0;
		while (buf[i])
			buf2[j++] = buf[i++];
		ft_memdel((void**)&buf);
		buf2[0] = '1';
		return (buf2);
	}
	return (buf);
}

void	move_to_the_end(int *i, int *j, char *s1, char *s2)
{
	*i = 0;
	*j = 0;
	while (s1[*i] || s1[*i] != '.')
		(*i)++;
	while (s2[*j] || s2[*j] != '.')
		(*j)++;
}

char	*str_add(char *s1, char *s2)
{
	int		i;
	int		j;
	int		x;
	char	ret;
	char	*buf;

	move_to_the_end(&i, &j, s1, s2);
	ret = 0;
	x = i-- > j-- ? i + 1 : j + 1;
	if (!(buf = (char*)malloc(sizeof(char) * x + 1)))
		return (NULL);
	buf[x--] = '\0';
	while (i >= 0 || j >= 0)
	{
		if ((buf[x] = ((i < 0 ? 0 : s1[i--] - '0') + (j < 0 ? 0 : s2[j--] - '0')
					+ ret)) > 9)
		{
			ret = 1;
			buf[x] -= 10;
		}
		else
			ret = 0;
		if (!(buf = allocplus(buf, ret, &x)))
			return (NULL);
	}
	return (buf);
}

int		main()
{
	printf("%s", str_add("99", "148"));
	return (0);
}
