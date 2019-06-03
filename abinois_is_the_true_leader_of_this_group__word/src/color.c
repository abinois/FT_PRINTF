/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:11:19 by abinois           #+#    #+#             */
/*   Updated: 2019/04/26 14:11:40 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	fill_colors(char **color)
{
	color[0] = "{red}";
	color[1] = "{green}";
	color[2] = "{yellow}";
	color[3] = "{blue}";
	color[4] = "{magenta}";
	color[5] = "{cyan}";
	color[6] = "{black}";
	color[7] = "{white}";
	color[8] = "error";
	color[9] = "\033[31m";
	color[10] = "\033[32m";
	color[11] = "\033[33m";
	color[12] = "\033[34m";
	color[13] = "\033[35m";
	color[14] = "\033[36m";
	color[15] = "\033[0m";
	color[16] = "\033[37m";
}

int		what_color(char *buf, int i)
{
	int		x;
	int		a;
	char	*color[17];

	fill_colors(color);
	x = i;
	a = 0;
	while (a <= 7 && ft_strncmp(color[a], buf + x, ft_strlen(color[a])))
		a++;
	return (a == 8 ? -1 : a);
}

int		return_value(char *buf)
{
	int		x;
	int		i;

	x = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '{' && what_color(buf, i) >= 0)
			while (buf[i] != '}')
				i++;
		else
			x++;
	}
	return (x);
}

void	put_color_printf(char *buf, int x)
{
	int		i;
	int		k;
	int		c;
	char	*color[15];

	fill_colors(color);
	i = -1;
	while (++i < x)
	{
		k = 0;
		while ((i + k) < x && buf[i + k] != '{')
			k++;
		printf("k = %d\n", k);
		if (k)
			ft_putnstr(buf + i, k);
		i += k;
		if (i < x && buf[i] == '{' && (c = what_color(buf, i)) >= 0)
		{
			ft_putstr(color[c + 9]);
			while (buf[i] != '}')
				i++;
		}
	}
	printf("yes\n");
	printf("k = %d\n", k);
	printf("i = %d\n", i);
	printf("x = %d\n", x);
}
