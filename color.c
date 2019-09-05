/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:11:19 by abinois           #+#    #+#             */
/*   Updated: 2019/07/03 18:52:35 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

char	*reput_backzer(char **str)
{
	size_t	i;

	i = -1;
	while ((*str)[++i])
		if ((*str)[i] == -1)
			(*str)[i] = 0;
	return (*str);
}

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
	color[9] = "{rev}";
	color[10] = "{blink}";
	color[11] = "{bold}";
	color[12] = "{over}";
	color[13] = "{italic}";
	color[14] = "{orange}";
	color[15] = "{purple}";
	color[16] = "{pink}";
	color[17] = "error";
	color[18] = "\033[31m";
	color[19] = "\033[32m";
	color[20] = "\033[33m";
	color[21] = "\033[34m";
	color[22] = "\033[35m";
	color[23] = "\033[36m";
	color[24] = "\033[30m";
	color[25] = "\033[4m";
	color[26] = "\033[0m";
	color[27] = "\033[7m";
	color[28] = "\033[5m";
	color[29] = "\033[1m";
	color[30] = "\033[9m";
	color[31] = "\033[3m";
	color[32] = "\033[38;5;208m";
	color[33] = "\033[38;5;129m";
	color[34] = "\033[38;5;206m";
}

int		what_color(char *buf, int i)
{
	int		x;
	int		a;
	char	*color[35];

	fill_colors(color);
	x = i;
	a = 0;
	while (a <= 16 && ft_strncmp(color[a], buf + x, ft_strlen(color[a])))
		a++;
	return (a == 17 ? -1 : a);
}

int		return_value(char *buf)
{
	int		x;
	int		i;
	int		c;

	x = 0;
	i = -1;
	while (buf[++i])
		if (buf[i] == '{' && (c = what_color(buf, i)) >= 0)
		{
			if (c < 7)
				x += 5;
			else if (c < 14)
				x += 4;
			else if (c < 17)
				x += 11;
			while (buf[i] != '}')
				i++;
		}
		else
			x++;
	return (x);
}

int		put_color(char *buf, int x, int i)
{
	int		k;
	int		c;
	char	*color[35];

	fill_colors(color);
	if (g_fd < 0 || g_fd > OPEN_MAX)
		return (-1);
	while (++i < x)
	{
		k = 0;
		while ((i + k) < x && buf[i + k] != '{')
			k++;
		if (k)
			write(g_fd, buf + i, k);
		i += k;
		if (i < x && buf[i] == '{' && (c = what_color(buf, i)) >= 0)
		{
			ft_putstr_fd(color[c + 18], g_fd);
			while (buf[i] != '}')
				i++;
		}
		else if (i < x && buf[i] == '{')
			write(g_fd, buf + i, 1);
	}
	return (0);
}
