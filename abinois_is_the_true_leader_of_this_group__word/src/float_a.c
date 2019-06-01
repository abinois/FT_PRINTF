/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/31 18:48:12 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Get all parts of the float : exponent, mantissa, sign, decimal, fractional.
*/

char	*over_63(t_float *infloat, char **res, int x, int i)
{
	char	*buffer;

	if (!(buffer = ft_strnew(1)))
		return (NULL);
	buffer[0] = '1';
	while (++x <= (int)I->expo - i)
		if (!(buffer = str_times_two(&buffer, 0, 0)))
			return (NULL);
	x = 0;
	while (i >= 0)
		if ((I->mantissa)[i--] == '1')
		{
			while (x-- > 0)
				if (!(buffer = str_times_two(&buffer, 0, 0)))
					return (NULL);
			if (!(*res = ft_str_add(&buffer, res, 2)))
				return (NULL);
			x = 1;
		}
		else
			x++;
	ft_memdel((void **)&buffer);
	return (*res);
}

char	*deci_float(t_float *infloat, long double nb)
{
	char	*res;
	char	*llutoa;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!(res = ft_memset(ft_strnew(1), 48, 1)) && nb > -1 && nb < 1)
		return (res);
	while ((int)I->expo - i > 0 && i < 63)
		i++;
	i++;
	while (--i >= 0 && (int)I->expo - i <= 63)
		if ((I->mantissa)[i] == '1')
		{
			if (!(llutoa = ft_llutoa(ft_po(2, (int)I->expo - i))))
				ft_memdel((void**)&res);
			if (!llutoa || !(res = ft_str_add(&res, &llutoa, 3)))
				return (NULL);
		}
	if (i >= 0 && (int)I->expo - i > 63)
		if (!(res = over_63(I, &res, x, i)))
			return (NULL);
	return (res);
}

char	*fracti_float(t_float *infloat, int i)
{
	char	*res;
	char	*buffer;
	int		x;

	while ((int)I->expo - i > -1 && I->mantissa[i])
		i++;
	buffer = ft_strnew(1);
	if (!(res = ft_strnew(1)))
		ft_memdel((void**)&buffer);
	if (!res || !buffer)	
		return (NULL);
	buffer[0] = '5';
	res[0] = '0';
	x = I->expo < 0 ? -(I->expo + 1) : 0;
	while ((I->mantissa)[i])
		if ((I->mantissa)[i++] == '1')
		{
			if (fracti_algo(&buffer, &res, &x) == -1)
				return (NULL);
		}
		else
			x++;
	ft_memdel((void**)&buffer);
	return (res);
}

int		fracti_algo(char **buffer, char **res, int *x)
{
	char	*zer;

	zer = "0";
	while ((*x)-- > 0)
	{
		if (!(*buffer = str_by_two(buffer, 0, -1)))
		{
			ft_memdel((void**)res);
			return (-1);
		}
		if (!(*res = ft_strjoinfr(res, &zer, 1)))
		{
			ft_memdel((void**)buffer);
			return (-1);
		}
	}
	if (!(*res = ft_str_add(buffer, res, 2)))
	{
		ft_memdel((void**)buffer);
		return (-1);
	}
	*x = 1;
	return (0);
}

int		preci_float(char **fracti_str, char **deci_str, t_flag flagz)
{
	char	*new;
	int		i;

	if (ft_strlen(*fracti_str) <= F.preci)
	{
		if (!(new = ft_strnew(F.preci)))
			return (-1);
		new = (char*)ft_memset(new, '0', F.preci);
		new = ft_strncpy(new, *fracti_str, ft_strlen(*fracti_str));
		ft_memdel((void**)fracti_str);
		*fracti_str = new;
		return (0);
	}
	i = F.preci;
	if ((*fracti_str)[i--] >= '5' && ((*fracti_str)[i] += 1))
		while ((*fracti_str)[i] > '9' && i >= 0 && ((*fracti_str)[i--] = '0'))
			if (i >= 0)
				(*fracti_str)[i] += 1;
	if (i == -1)
		if (!(new = ft_llutoa(ft_po(2, 0)))
			|| !(*deci_str = ft_str_add(deci_str, &new, 3)))
			return (-1);
	if (!(*fracti_str = ft_strsub((const char**)fracti_str, 0, F.preci, 1)))
		return (-1);
	return (0);
}
