/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:48:32 by abinois           #+#    #+#             */
/*   Updated: 2019/06/04 16:07:42 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char		*p_sign_float(char **str, t_flag flagz, t_float *infloat)
{
	char	*new;
	char	*sign[3];

	sign[0] = "-";
	sign[1] = "+";
	sign[2] = " ";
	new = *str;
	if (I->sign)
	{
		if (!(new = ft_strjoinfr(&(sign[0]), str, 2)))
			return (NULL);
	}
	else if (F.plus)
	{
		if (!(new = ft_strjoinfr(&(sign[1]), str, 2)))
			return (NULL);
	}
	else if (F.sp)
		if (!(new = ft_strjoinfr(&(sign[2]), str, 2)))
			return (NULL);
	*str = NULL;
	return (new);
}

int			get_zersp(t_float *infloat, t_flag flagz)
{
	size_t	z;
	size_t	i;

	z = ft_strlen(I->deci_str) + F.preci;
	z += F.hash || F.preci ? 1 : 0;
	z += I->sign || F.plus || F.sp ? 1 : 0;
	F.field = F.field > z ? F.field - z : 0;
	if (F.field)
	{
		if (!(I->zersp = (char*)malloc(sizeof(char) * (F.field + 1))))
			return (-1);
		i = 0;
		while (F.field--)
			(I->zersp)[i++] = F.zer ? '0' : ' ';
		(I->zersp)[i] = '\0';
		return (0);
	}
	return (0);
}

t_float		*reset_float(t_float *infloat)
{
	if (!(I = (t_float *)malloc(sizeof(t_float))))
		return (NULL);
	I->mantissa = NULL;
	I->sign = false;
	I->expo = 0;
	I->result = NULL;
	I->fracti_str = NULL;
	I->deci_str = NULL;
	I->zersp = NULL;
	return (I);
}

char		*free_float(t_float **infloat)
{
	if ((*I)->mantissa)
		ft_memdel((void**)&((*I)->mantissa));
	if ((*I)->result)
		ft_memdel((void**)&((*I)->result));
	if ((*I)->fracti_str)
		ft_memdel((void**)&((*I)->fracti_str));
	if ((*I)->deci_str)
		ft_memdel((void**)&((*I)->deci_str));
	if ((*I)->zersp)
		ft_memdel((void**)&((*I)->zersp));
	ft_memdel((void**)I);
	return (NULL);
}
