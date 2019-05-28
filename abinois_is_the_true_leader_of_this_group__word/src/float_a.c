/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:39:36 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/28 11:54:16 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
 ** Get all parts of the float : exponent, mantissa, sign, decimal, fractional.
 */

char		*over_63(t_float *infloat, char *res, int x, int i)
{
    char	*buffer;

    if (!(buffer = (char*)malloc(sizeof(char) * 2)))
	return (NULL);
    buffer = "1\0";
    while (++x <= (int)I->expo - i)
	if (!(buffer = str_times_two(buffer)))
	    return (NULL);
    x = 0;
    while (i >= 0)
    {
	if ((I->mantissa)[i--] == '1')
	{
	    while (x-- > 0)
		if (!(buffer = str_times_two(buffer)))
		    return (NULL);
	    if (!(res = ft_str_add(buffer, res)))
		return (NULL);
	    x = 1;
	}
	else
	    x++;
    }
    free(buffer); 
    return (res);
}

char		*deci_float(t_float *infloat, long double nb)
{
    char	*res;
    int		i;
    int		x;

    x = 0;
    i = 0;
    while ((int)I->expo - i > 0 && i < 63)
	i++;
    if (!(res = (char*)malloc(sizeof(char) * 2)))
	return (NULL);
    res = "0\0";
    if (nb < 1 && nb > -1)
	return (res);
    while (i >= 0 && (int)I->expo - i <= 63)
    {
	if ((I->mantissa)[i] == '1')
	    if (!(res = ft_str_add(res, ft_llutoa(ft_pow(2, (int)I->expo - i)))))
		return (NULL);
	i--;
    }
    if (i >= 0 && (int)I->expo - i > 63)
	if (!(res = over_63(I, res, x, i)))
	    return (NULL);
    return (res);
}

char		*fracti_float(t_float *infloat)
{
    char	*res;
    char	*buffer;
    int		i;
    int		x;

    i = 0;
    while ((int)I->expo - i > -1 && i < 63)
	i++;
    if (!(buffer = (char *)malloc(sizeof(char) * 2)))
	return (NULL);
    buffer = "5\0";
    if (!(res = (char *)malloc(sizeof(char) * 2)))
	return (NULL);
    res = "0\0";
    x = I->expo < 0 ? -(I->expo + 1) : 0;
    while ((I->mantissa)[i])
    {
	if ((I->mantissa)[i++] == '1')
	{
	    if (fracti_algo(&buffer, &res, &x) == -1)
		return (NULL);
	}
	else
	    x++;
    }
    return (res);
}

int		fracti_algo(char **buffer, char **res, int *x)
{
    while ((*x)-- > 0)
    {
	if (!(*buffer = str_by_two(*buffer)))
	    return (-1);
	if (!(*res = ft_strjoin(*res, "0")))
	    return (-1);
    }
    if (!(*res = ft_str_add(*buffer, *res)))
	return (-1);
    *x = 1;
    return (0);
}
