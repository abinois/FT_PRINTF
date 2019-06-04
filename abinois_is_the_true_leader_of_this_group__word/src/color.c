/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:11:19 by abinois           #+#    #+#             */
/*   Updated: 2019/06/04 10:37:03 by abinois          ###   ########.fr       */
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
	color[7] = "{under}";
	color[8] = "{reset}";
	color[9] = "error";
	color[10] = "\033[31m";
	color[11] = "\033[32m";
	color[12] = "\033[33m";
	color[13] = "\033[34m";
	color[14] = "\033[35m";
	color[15] = "\033[36m";
	color[16] = "\033[30m";
	color[17] = "\033[4m";
	color[18] = "\033[0m";
}

int		what_color(char *buf, int i)
{
	int		x;
	int		a;
	char	*color[19];

	fill_colors(color);
	x = i;
	a = 0;
	while (a <= 8 && ft_strncmp(color[a], buf + x, ft_strlen(color[a])))
		a++;
	return (a == 9 ? -1 : a);
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
	char	*color[19];

	fill_colors(color);
	i = -1;
	while (++i < x)
	{
		k = 0;
		while ((i + k) < x && buf[i + k] != '{')
			k++;
		if (k)
			write(1, buf + i, k);
		i += k;
		if (i < x && buf[i] == '{' && (c = what_color(buf, i)) >= 0)
		{
			ft_putstr(color[c + 10]);
			while (buf[i] != '}')
				i++;
		}
		else if (i < x && buf[i] == '{')
			write(1, buf + i, 1);
	}
}
