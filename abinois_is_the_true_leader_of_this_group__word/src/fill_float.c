/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:45:46 by abinois           #+#    #+#             */
/*   Updated: 2019/05/29 15:09:29 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

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

char		*get_zersp(t_float *infloat, t_flag flagz, char *deci_str)
{
	size_t	z;
	size_t	i;
	char	*zersp;

	z = ft_strlen(deci_str) + F.preci;
	z += F.hash || F.preci ? 1 : 0;
	z += I->sign || F.plus || F.sp ? 1 : 0;
	F.field = F.field > z ? F.field - z : 0;
	if (F.field)
	{
		if (!(zersp = (char*)malloc(sizeof(char) * (F.field + 1))))
			return (NULL);
		i = 0;
		while (F.field--)
			zersp[i++] = F.zer ? '0' : ' ';
		zersp[i] = '\0';
		return (zersp);
	}
	return (NULL);
}

char		*get_float(t_flag flagz, va_list ap)
{
	long double	nb;
	t_float		*infloat;
	char		*deci_str;
	char		*fracti_str;
	char		*zersp;

	if (!(I = (t_float *)malloc(sizeof(t_float))))
		return (NULL);
	nb = check_f_flagz(F, ap);
	if (!(I->mantissa = get_mantissa(nb)))
		return (NULL);
	I->expo = get_exponent(nb);
	I->sign = nb >= 0 ? false : true;
	if (!(deci_str = deci_float(I, nb)))
		return (NULL);
	if (!(fracti_str = fracti_float(I, 0)))
		return (NULL);
	if (preci_float(&fracti_str, &deci_str, F) == -1)
		return (NULL);
	if (!(zersp = get_zersp(I, F, deci_str)))
		return (NULL);
	if (F.minus)
	{
		if (!(deci_str = p_sign_float(deci_str, F, I)))
			return (NULL);
		if (F.hash || F.preci)
			if (!(I->result = ft_strjoinfr(deci_str, ".", 1)))
				return (NULL);
		if (F.preci)
			if (!(I->result = ft_strjoinfr(I->result, fracti_str, 3)))
				return (NULL);
		if (zersp)
			if (!(I->result = ft_strjoinfr(I->result, zersp, 3)))
				return (NULL);
	}
	else if (F.zer)
	{
		if (zersp)
			if (!(deci_str = ft_strjoinfr(zersp, deci_str, 3)))
				return (NULL);
		if (!(I->result = p_sign_float(deci_str, F, I)))
			return (NULL);
		if (F.hash || F.preci)
			if (!(I->result = ft_strjoinfr(I->result, ".", 1)))
				return (NULL);
		if (F.preci)
			if (!(I->result = ft_strjoinfr(I->result, fracti_str, 3)))
				return (NULL);
	}
	else
	{
		if (!(deci_str = p_sign_float(deci_str, F, I)))
			return (NULL);
		I->result = deci_str;
		if (zersp)
			if (!(I->result = ft_strjoinfr(zersp, deci_str, 3)))
				return (NULL);
		if (F.hash || F.preci)
			if (!(I->result = ft_strjoinfr(I->result, ".", 1)))
				return (NULL);
		if (F.preci)
			if (!(I->result = ft_strjoinfr(I->result, fracti_str, 3)))
				return (NULL);
	}
	return (I->result);
}
