/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:45:46 by abinois           #+#    #+#             */
/*   Updated: 2019/05/29 19:47:11 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char		*get_f_start(t_float **infloat, LD *nb, VL ap, t_flag flagz)
{
	if (!(*I = reset_float(*I)))
		return (NULL);
	*nb = check_f_flagz(F, ap);
	if (!((*I)->mantissa = get_mantissa(*nb)))
		return (free_float(*I));
	(*I)->expo = get_exponent(*nb);
	(*I)->sign = *nb >= 0 ? false : true;
	if (!((*I)->deci_str = deci_float(*I, *nb)))
		return (free_float(*I));
	if (!((*I)->fracti_str = fracti_float(*I, 0)))
		return (free_float(*I));
	if (preci_float(&((*I)->fracti_str), &((*I)->deci_str), F) == -1)
		return (free_float(*I));
	if (get_zersp(*I, F) == -1)
		return (free_float(*I));
	return ("ok!");
}

char		*get_f_min(t_float *infloat, t_flag flagz)
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
	return ("ok!");
}

char		*get_f_zer(t_float *infloat, t_flag flagz)
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
	return ("ok!");
}

char		*get_f_else(t_float *infloat, t_flag flagz)
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
	return ("ok!");
}

char		*get_float(t_flag flagz, va_list ap)
{
	long double	nb;
	t_float		*infloat;
	char		*result;

	I = NULL;
	if (!(get_f_start(&I, &nb, ap, F)))
		return (NULL);
	if (F.minus)
	{
		if (!(get_f_min(I, F)))
			return (NULL);
	}
	else if (F.zer)
	{
		if (!(get_f_zer(I, F)))
			return (NULL);
	}
	else
	{
		if (!(get_f_else(I, F)))
			return (NULL);
	}
	result = I->result;
	free_float(I);
	return (I->result);
}
