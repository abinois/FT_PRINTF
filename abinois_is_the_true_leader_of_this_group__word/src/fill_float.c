/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:45:46 by abinois           #+#    #+#             */
/*   Updated: 2019/05/29 16:44:55 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char		*p_sign_float(char *str, t_flag flagz, t_float *infloat)
{
	if (I->sign)
		str = ft_strjoinfr("-", str, 2);
	else if (F.plus)
		str = ft_strjoinfr("+", str, 2);
	else if (F.sp)
		str = ft_strjoinfr(" ", str, 2);
	return (str);
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

char		*free_float(t_float *infloat)
{
	if (I->mantissa)
		ft_memdel((void**)&(I->mantissa));
	if (I->result)
		ft_memdel((void**)&(I->result));
	if (I->fracti_str)
		ft_memdel((void**)&(I->fracti_str));
	if (I->deci_str)
		ft_memdel((void**)&(I->deci_str));
	if (I->zersp)
		ft_memdel((void**)&(I->zersp));
	return (NULL);
}

char		*get_float(t_flag flagz, va_list ap)
{
	long double	nb;
	t_float		*infloat;

	I = NULL;
	if (!(I = reset_float(I)))
		return (NULL);
	nb = check_f_flagz(F, ap);
	if (!(I->mantissa = get_mantissa(nb)))
		return (free_float(I));
	I->expo = get_exponent(nb);
	I->sign = nb >= 0 ? false : true;
	if (!(I->deci_str = deci_float(I, nb)))
		return (free_float(I));
	if (!(I->fracti_str = fracti_float(I, 0)))
		return (free_float(I));
	if (preci_float(&(I->fracti_str), &(I->deci_str), F) == -1)
		return (free_float(I));
	if (get_zersp(I, F) == -1)
		return (free_float(I));
	if (F.minus)
	{
		if (!(I->deci_str = p_sign_float(I->deci_str, F, I)))
			return (free_float(I));
		if (F.hash || F.preci)
			if (!(I->result = ft_strjoinfr(I->deci_str, ".", 1)))
				return (free_float(I));
		if (F.preci)
			if (!(I->result = ft_strjoinfr(I->result, I->fracti_str, 3)))
				return (free_float(I));
		if (I->zersp)
			if (!(I->result = ft_strjoinfr(I->result, I->zersp, 3)))
				return (free_float(I));
	}
	else if (F.zer)
	{
		if (I->zersp)
			if (!(I->deci_str = ft_strjoinfr(I->zersp, I->deci_str, 3)))
				return (free_float(I));
		if (!(I->result = p_sign_float(I->deci_str, F, I)))
			return (free_float(I));
		if (F.hash || F.preci)
			if (!(I->result = ft_strjoinfr(I->result, ".", 1)))
				return (free_float(I));
		if (F.preci)
			if (!(I->result = ft_strjoinfr(I->result, I->fracti_str, 3)))
				return (free_float(I));
	}
	else
	{
		if (!(I->deci_str = p_sign_float(I->deci_str, F, I)))
			return (free_float(I));
		I->result = I->deci_str;
		if (I->zersp)
			if (!(I->result = ft_strjoinfr(I->zersp, I->deci_str, 3)))
				return (free_float(I));
		if (F.hash || F.preci)
			if (!(I->result = ft_strjoinfr(I->result, ".", 1)))
				return (free_float(I));
		if (F.preci)
			if (!(I->result = ft_strjoinfr(I->result, I->fracti_str, 3)))
				return (free_float(I));
	}
	return (I->result);
}
