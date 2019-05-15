/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:23:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/15 19:21:57 by edillenb         ###   ########.fr       */
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
	bool		bigl;
	bool		h;
	bool		hh;
	char		conv;
	long long	nb;
}				t_flag;

int				ft_printf(const char *fmt, ...);
// tools.c    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void			reset_flagz(t_flag *flagz);
char			*p_sign(t_flag *flagz, char *res, size_t *i);
char			*p_toa(char *toa, char *res, size_t *c);
char			*p_zer(size_t flag, char *res, size_t *c, size_t l_nb);
char			*llhexatoa(ULL nbr);
// buffer.c   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char			*m_to_buf(int *m, char *buf, const char *fmt, int i);
char			*percent_to_buf(int *m, char *buf, int *i);
int				m_or_percent(int *m, char **buf, const char *fmt, int *i);
char			*arg_to_buf(char *arg, char **buf);
// flag.c     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void			check_first_flagz(const char *fmt, t_flag *flagz, int *i);
void			check_l_flagz(const char *fmt, t_flag *flagz, int *i);
void			check_h_flagz(const char *fmt, t_flag *flagz, int *i);
void			check_field_preci_flagz(const char *fmt, t_flag *flagz, int *i);
char			*check_all(const char *fmt, t_flag *flagz, int *i, va_list ap);
// convert.c  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char			*check_conv1(const char *fmt, t_flag flagz, int *i, va_list ap);
char			*check_conv2(const char *fmt, t_flag flagz, int *i, va_list ap);
char			*check_conv3(const char *fmt, t_flag flagz, int *i, va_list ap);
long long		check_d_i_flagz(t_flag flagz, va_list ap);
ULL				check_poux_flagz(t_flag flagz, va_list ap);
// check_d.c  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char			*malloc_str_d(t_flag flagz, va_list ap);
char			*fill_str_d(t_flag flagz, size_t lmax, char *toa, char *res);
// check_ou.c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char			*put_hash(char *res, size_t *c, t_flag flagz, size_t l_nb);
char			*fill_str_ou(t_flag flagz, size_t lmax, char *toa, char *res);
char			*malloc_str_ou(t_flag flagz, va_list ap);
// check_xp.c  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char			*malloc_str_xp(t_flag flagz, va_list ap);
char			*fill_str_xp(t_flag flagz, size_t lmax, char *toa, char *res);
char			*fill_nomin_xp(t_flag flagz, size_t l_nb, char *res, size_t *c);
// check_s.c  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
char			*malloc_str_c(t_flag flagz, va_list ap);
char			*malloc_str_s(t_flag flagz, va_list ap);
char			*fill_str_s(t_flag flagz, size_t lmax, char *toa, char *res);
#endif
