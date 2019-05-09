/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:23:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/09 11:06:36 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

typedef struct	s_flag
{
	bool		zer;
	bool		minus;
	bool		sp;
	bool		plus;
	bool		hash;
	int			field;
	bool		dot;
	int			preci;
	bool		l;
	bool		ll;
	bool		L;
	bool		h;
	bool		hh;
}				t_flag;

int		ft_printf(const char *fmt, ...);

void	reset_flagz(t_flag *flagz);
void	print_flagz(t_flag *flagz);

char	*m_to_buf(int *m, char *buf, const char *fmt, int i);
char	*percent_to_buf(int *m, char *buf, int *i);
int		m_or_percent_to_buf(int *m, char *buf, const char *fmt, int *i);

void	check_first_flagz(const char *fmt, t_flag *flagz, int *i);
void	check_l_flagz(const char *fmt, t_flag *flagz, int *i);
void	check_h_flagz(const char *fmt, t_flag *flagz, int *i);
void	check_dot_flag(const char *fmt, t_flag *flagz, int *i);
void	check_field_flag(const char *fmt, t_flag *flagz, int *i);

int		check_conv1(const char *fmt, t_flag *flagz, int *i);
int		check_conv2(const char *fmt, t_flag *flagz, int *i);
int		check_conv3(const char *fmt, t_flag *flagz, int *i);

#endif
