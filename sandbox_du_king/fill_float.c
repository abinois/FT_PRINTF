/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:45:46 by abinois           #+#    #+#             */
/*   Updated: 2019/05/27 20:43:57 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char		*p_sign_float(char *str, t_flag flagz, t_float *infloat)
{
	if (infloat->sign)
		str = ft_strjoin("-", str);
	else if (F.plus)
		str = ft_strjoin("+", str);
	else if (F.sp)
		str = ft_strjoin(" ", str);
	return (str);
}

char		*get_zersp(t_float *infloat, t_flag flagz, char *deci_str)
{
	size_t	z;
	size_t	i;
	char	*zersp;

	z = ft_strlen(deci_str) + F.preci;
	z += F.hash || F.preci ? 1 : 0;
	z += infloat->sign || F.plus || F.sp ? 1 : 0;
	F.field = F.field > z ? F.field - z : 0;
	zersp = NULL;
	if (F.field)
	{
		if (!(zersp = (char*)malloc(sizeof(char) * (F.field + 1))))
			return (NULL);
		i = 0;
		while (F.field--)
			zersp[i++] = F.zer ? '0' : ' ';
		zersp[i] = '\0';
	}
	return (zersp);
}
