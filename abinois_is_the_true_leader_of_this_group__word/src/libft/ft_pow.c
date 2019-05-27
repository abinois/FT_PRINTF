/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:08:20 by abinois           #+#    #+#             */
/*   Updated: 2019/05/24 15:41:59 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_pow(unsigned long long nb, int po)
{
	unsigned long long	res;

	res = 1;
	if (!po)
		return (1);
	if (po < 0 || !nb)
		return (0);
	while (po--)
		res *= nb;
	return (res);
}
