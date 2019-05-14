/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:23:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/14 17:22:33 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <string.h>

# define UI		unsigned int
# define ULL	unsigned long long
# define F		flagz

typedef struct	s_flag
{
	bool		zer;
	bool		minus;
	bool		sp;
	bool		plus;
	bool		hash;
	size_t		field;
	bool		dot;
	size_t		preci;
	bool		l;
	bool		ll;
	bool		L;
	bool		h;
	bool		hh;
}				t_flag;

int			ft_printf(const char *fmt, ...);

void		reset_flagz(t_flag *F);
void		print_flagz(t_flag *F);

char		*m_to_buf(int *m, char *buf, const char *fmt, int i);
char		*percent_to_buf(int *m, char *buf, int *i);
int			m_or_percent_to_buf(int *m, char **buf, const char *fmt, int *i);
char		*arg_to_buf(char *arg, char **buf);

void		check_first_flagz(const char *fmt, t_flag *F, int *i);
void		check_l_flagz(const char *fmt, t_flag *F, int *i);
void		check_h_flagz(const char *fmt, t_flag *F, int *i);
void		check_field_and_dot_flagz(const char *fmt, t_flag *F, int *i);
char		*check_all(const char *fmt, t_flag *F, int *i, va_list ap);

char		*check_conv1(const char *fmt, t_flag F, int *i, va_list ap);
char		*check_conv2(const char *fmt, t_flag F, int *i, va_list ap);
char		*check_conv3(const char *fmt, t_flag F, int *i, va_list ap);

long long	check_d_i_flagz(t_flag F, va_list ap);
char		*malloc_str_d_i(t_flag F, va_list ap);
char		*fill_string(t_flag F, long long nb, size_t lmax, char *lltoa);
char		*put_sign(t_flag F, long long nb, char *res, size_t *i);

ULL			check_u_flagz(t_flag F, va_list ap);
char		*malloc_str_u(t_flag F, va_list ap);
char		*fill_str_u(t_flag F, size_t lmax, char *toa, char *res);
char		*put_toa(char *toa, char *res, size_t *c);

char		*malloc_str_o(t_flag F, va_list ap);
char		*fill_str_o(t_flag F, size_t lmax, char *toa, char *res);

char		*malloc_str_c(t_flag F, va_list ap);

char		*malloc_str_xX(t_flag F, va_list ap);
char		*fill_str_xX(t_flag F, size_t lmax, char *toa, char *res);

char		*llhexatoa(ULL nbr);
char		*malloc_str_p(t_flag F, va_list ap);
#endif
