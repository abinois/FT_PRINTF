/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:45:46 by abinois           #+#    #+#             */
/*   Updated: 2019/05/28 20:57:36 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char		*p_sign_float(char *str, t_flag flagz, t_float *infloat)
{
	if (I->sign)
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
	I->mantissa = get_mantissa(nb);
	I->expo = get_exponent(nb);
	I->sign = nb >= 0 ? false : true;
	deci_str = deci_float(I, nb);
	fracti_str = fracti_float(I, 0);
	preci_float(&fracti_str, &deci_str, F);
	zersp = get_zersp(I, F, deci_str);
	if (F.minus)
	{
		deci_str = p_sign_float(deci_str, F, I);
		if (F.hash || F.preci)
			I->result = ft_strjoin(deci_str, ".");
		if (F.preci)
			I->result = ft_strjoin(I->result, fracti_str);
		if (zersp)
			I->result = ft_strjoin(I->result, zersp);
	}
	else if (F.zer)
	{
		if (zersp)
			deci_str = ft_strjoin(zersp, deci_str);
		I->result = p_sign_float(deci_str, F, I);
		if (F.hash || F.preci)
			I->result = ft_strjoin(I->result, ".");
		if (F.preci)
			I->result = ft_strjoin(I->result, fracti_str);
	}
	else
	{
		deci_str = p_sign_float(deci_str, F, I);
		I->result = deci_str;
		if (zersp)
			I->result = ft_strjoin(zersp, deci_str);
		if (F.hash || F.preci)
			I->result = ft_strjoin(I->result, ".");
		if (F.preci)
			I->result = ft_strjoin(I->result, fracti_str);
	}
	return (I->result);
}
