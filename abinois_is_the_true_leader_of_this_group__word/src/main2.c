/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:10:51 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/31 19:12:38 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <unistd.h>

void print(char *buff, char *buff2, int st_out, int p_out, int ft_p_out)
{
	int k;

	k = 0;
	if (!(k = ft_strcmp(buff, buff2)) || p_out == ft_p_out)
		write(st_out, "\x1B[32mOK\x1B[0m\n", 18);
	else
		write(st_out, "\x1B[31mWRONG!\x1B[0m\n", 18);
	dup2(st_out, fileno(stdout));
	printf("\x1B[0m%s|%s -- printf out :%d | ft_printf_out :%d\n", buff,
			buff2, p_out, ft_p_out);
	fflush(stdout);
}

void truc(char *buff, int fid[2])
{
	int r;

	r = 0;
	fflush(stdout);
	r = read(fid[0], buff, 99);
	buff[r] = '\0';
}

int main(void)
{
	char buff[100];
	char buff2[100];
	int fid[2];
	int fid2[2];
	char *test;
	long double i;
	int p_out;
	int ft_p_out;
	int cpt;
	int st_out;

	i = 10.10;
	cpt = 10;
	st_out = dup(fileno(stdout));
	pipe(fid);
	pipe(fid2);

	test = " %-10.o";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, 0);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, 0);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %#-010.o";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, 0);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, 0);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %.o";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, 0);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, 0);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %-10.o";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, 0);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, 0);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %0.2p";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, NULL);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, NULL);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %0-.2p";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, test);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, test);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %#020p";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, test);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, test);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = " %-20p";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, test);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, test);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = "bonjour  %c %c";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, '\0', '\t');
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, '\0', '\t');
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = "%+.i et % kkk !!";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, 0, 0);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, 0, 0);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

	test = "\ntoto et %00009u%-2lu mimi et titi%--14u";
	dup2(fid[1], fileno(stdout));
	p_out = printf(test, 0, (unsigned long)14, 200);
	truc(buff, fid);
	dup2(fid2[1], fileno(stdout));
	ft_p_out = ft_printf(test, 0, (unsigned long)14, 200);
	truc(buff2, fid2);
	print(buff, buff2, st_out, p_out, ft_p_out);

}
