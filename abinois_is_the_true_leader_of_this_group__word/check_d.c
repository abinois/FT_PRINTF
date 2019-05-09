/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 16:10:59 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft/libft.h>
#include <stdarg.h>
#include <stdbool.h>

/*
** will malloc a new string if input is of type d or i
*/



long long	check_d_i_flagz(t_flag flagz, va_list ap)
{
	long long	number;

	if (flagz.l == true)
		return ((number = (long long)va_arg(ap, long)));
	if (flagz.ll == true)
		return ((number = va_arg(ap, long long)));
	if (flagz.h == true)
		return ((number = (long long)va_arg(ap, short));
	return ((number = (long long)va_arg(ap, int)));
}

char	*malloc_new_str_d_i(t_flag flagz, va_list ap, char *fmt)
{
	long long	number;
	char		*result_lltoa;
	char		*final_result;
	int			lltoa_len;
	int			final_len;

	number = check_d_i_flagz(flagz, ap);
	result_lltoa = ft_lltoa(number);
	lltoa_len = ft_strlen(result_lltoa);
	// check length specifier
	if (flag)
	final_len = itoa_len;
	if (flagz.field > itoa_len)
		final_len = flagz.field;
	if (flagz.preci + itoa_len > flagz.field)
		final_len = flagz.preci + itoa_len;
	if (result > 0 && flagz.plus == true)
		final_len++;
	ft_putnbr(final_len);
}

/*
** will malloc a new string if input is of type f
*/
