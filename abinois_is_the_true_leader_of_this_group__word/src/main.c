/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:02:39 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/09 21:41:42 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_llutoa(unsigned long long nbr);

int		main(int argc, char ** argv)
{
	unsigned long long	number;

	number = -123123;
	printf("%s\n", ft_llutoa(number));
	printf("%llu", number);
	return (0);
}
