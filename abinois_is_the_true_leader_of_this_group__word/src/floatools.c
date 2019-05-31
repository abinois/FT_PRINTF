/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:48:32 by abinois           #+#    #+#             */
/*   Updated: 2019/05/31 16:21:01 by edillenb         ###   ########.fr       */
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
		ft_memdel((void**)str);
	}
	else if (F.plus)
	{
		if (!(new = ft_strjoinfr(&(sign[1]), str, 2)))
			return (NULL);
		ft_memdel((void**)str);
	}
	else if (F.sp)
	{
		if (!(new = ft_strjoinfr(&(sign[2]), str, 2)))
			return (NULL);
		ft_memdel((void**)str);
	}
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
		ft_putstr("LOL\n");
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
	ft_putstr("1\n");
	if ((*I)->mantissa)
		ft_memdel((void**)&((*I)->mantissa));
	ft_putstr("2\n");
	if ((*I)->result == (*I)->deci_str)
		(*I)->deci_str = NULL;
	if ((*I)->result)
		ft_memdel((void**)&((*I)->result));
	ft_putstr("3\n");
	if ((*I)->fracti_str)
		ft_memdel((void**)&((*I)->fracti_str));
	ft_putstr("4\n");
	printf("this is the adress of deci_str : %p\n", (*I)->deci_str);
	if ((*I)->deci_str)
		ft_memdel((void**)&((*I)->deci_str));
	ft_putstr("5\n");
	if ((*I)->zersp)
		ft_memdel((void**)&((*I)->zersp));
	ft_putstr("6\n");
	ft_memdel((void**)I);
	ft_putstr("7\n");
	return (NULL);
}
