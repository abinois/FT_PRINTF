/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 17:43:03 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** will malloc a new string if input is of type d or i
*/

char		*fill_string(t_flag flagz, long long number, size_t final_len)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (final_len + 1))))
		return (NULL);
	result[final_len] = '\0';
}


long long	check_d_i_flagz(t_flag flagz, va_list ap)
{
	long long	number;

	if (flagz.l == true)
		return ((number = va_arg(ap, long)));
	if (flagz.ll == true)
		return ((number = va_arg(ap, long long)));
	if (flagz.h == true)
		return ((number = (short)va_arg(ap, int)));
	return ((number = va_arg(ap, int)));
}

char		*malloc_str_d_i(t_flag flagz, va_list ap, const char *fmt)
{
	long long	number;
	char		*result_lltoa;
	char		*final_result;
	size_t		final_len;

	number = check_d_i_flagz(flagz, ap);
	result_lltoa = ft_lltoa(number);
	final_len = ft_strlen(result_lltoa);
	if (flagz.field > final_len)
		final_len = flagz.field;
	if (flagz.preci > flagz.field)
		final_len = number < 0 ? flagz.preci + 1 : flagz.preci;
	if (number > 0 && (flagz.plus == true || flagz.sp == true))
		final_len++;
	ft_putstrclr("final_len :", "blue");
	ft_putnbr((int)final_len);
	return (result_lltoa);
}
