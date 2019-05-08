/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:06:59 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/08 20:02:14 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft/libft.h>
#include <stdarg.h>
#include <stdbool.h>

char	*malloc_new_string(t_flag flagz, va_list ap, char *fmt)
{
	long		number;
	char		*result_itoa;
	char		*final_result;
	int			itoa_len;
	int			final_len;

	number = (long)va_arg(fmt, int);
	result = ft_itoa(number);
	itoa_len = ft_strlen(result);

	final_len = itoa_len;
	if (flagz.field > itoa_len)
		final_len = flagz.field;
	if (flagz.preci + itoa_len > flagz.field)
		final_len = flagz.preci + itoa_len;
	if (result < 0 && flagz.field == true)
		final_len++;
}
