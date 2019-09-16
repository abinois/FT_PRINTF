/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:41:02 by abinois           #+#    #+#             */
/*   Updated: 2019/08/24 12:42:58 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_skip_char(char *line, char c, int i)
{
	if (c <= 0)
		return (i);
	while (line[i] && line[i] == c)
		i++;
	return (i);
}
