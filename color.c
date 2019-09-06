/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:11:19 by abinois           #+#    #+#             */
/*   Updated: 2019/09/06 13:20:21 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static char *g_color[39] =
{
	"{red}", "{green}", "{yellow}", "{blue}", "{magenta}", "{cyan}", "{black}",
	"{under}", "{reset}", "{rev}", "{blink}", "{bold}", "{over}", "{italic}",
	"{orange}", "{purple}", "{pink}", "{kaki}", "{grey}",
	"error",
	"\e[31m", "\e[32m", "\e[33m", "\e[34m", "\e[35m", "\e[36m", "\e[30m",
	"\e[4m", "\e[0m", "\e[7m", "\e[5m", "\e[1m", "\e[9m", "\e[3m",
	"\e[38;5;208m", "\e[38;5;129m", "\e[38;5;206m", "\e[38;5;143m",
	"\e[38;5;248m"
};

char	*reput_backzer(char **str)
{
	size_t	i;

	i = -1;
	while ((*str)[++i])
		if ((*str)[i] == -1)
			(*str)[i] = 0;
	return (*str);
}

int		what_color(char *buf, int i)
{
	int		a;

	a = 0;
	while (a <= 18 && ft_strncmp(g_color[a], buf + i, ft_strlen(g_color[a])))
		a++;
	return (a == 19 ? -1 : a);
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
			else if (c < 19)
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
			ft_putstr_fd(g_color[c + 20], g_fd);
			while (buf[i] != '}')
				i++;
		}
		else if (i < x && buf[i] == '{')
			write(g_fd, buf + i, 1);
	}
	return (0);
}
