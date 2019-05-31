/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:23:19 by abinois           #+#    #+#             */
/*   Updated: 2019/05/31 18:30:15 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <string.h>
# include <stdint.h>

# define F		flagz
# define I		infloat
# define LD 	long double
# define VL		va_list
# define UI		unsigned int
# define ULL	unsigned long long

typedef struct	s_float
{
	char		*mantissa;
	bool		sign;
	int			expo;
	char		*result;
	char		*fracti_str;
	char		*deci_str;
	char		*zersp;
}				t_float;

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

char			*put_sp(t_flag flagz, size_t *c, size_t lmax, char *res);
int				print__return(va_list ap, char **buf);
char			*reput_backzer(char **str);

void			reset_flagz(t_flag *flagz);
char			*p_sign(t_flag *flagz, char *res, size_t *i);
char			*p_toa(char *toa, char *res, size_t *c);
char			*p_zer(size_t flag, char *res, size_t *c, size_t l_nb);
char			*put_hash(char *res, size_t *c, t_flag flagz, size_t l_nb);

char			*m_to_buf(int *m, char *buf, const char *fmt, int i);
char			*percent_to_buf(int *m, char *buf, int *i);
int				m_or_percent(int *m, char **buf, const char *fmt, int *i);
char			*arg_to_buf(char **buf, char **arg);

void			check_first_flagz(const char *fmt, t_flag *flagz, int *i);
void			check_l_flagz(const char *fmt, t_flag *flagz, int *i);
void			check_h_flagz(const char *fmt, t_flag *flagz, int *i);
void			check_field_preci_flagz(const char *fmt, t_flag *flagz, int *i);
char			*check_all(const char *fmt, t_flag *flagz, int *i, VL ap);

char			*check_conv1(const char *fmt, t_flag flagz, int *i, VL ap);
char			*check_conv2(const char *fmt, t_flag flagz, int *i, VL ap);
char			*check_conv3(const char *fmt, t_flag flagz, int *i, VL ap);

char			*over_63(t_float *infloat, char **res, int x, int i);
char			*deci_float(t_float *infloat, LD nb);
char			*fracti_float(t_float *infloat, int i);
int				fracti_algo(char **buffer, char **res, int *x);
int				preci_float(char **fracti_str, char **deci_str, t_flag flagz);

char			*str_times_two(char **str);
char			*str_by_two(char **str);
char			*get_mantissa(LD dbl);
int16_t			get_exponent(LD dbl);

char			*p_sign_float(char **str, t_flag flagz, t_float *infloat);
int				get_zersp(t_float *infloat, t_flag flagz);
t_float			*reset_float(t_float *infloat);
char			*free_float(t_float **infloat);

char			*get_f_start(t_float **infloat, LD *nb, VL ap, t_flag flagz);
char			*get_f_min(t_float *infloat, t_flag flagz);
char			*get_f_zer(t_float *infloat, t_flag flagz);
char			*get_f_else(t_float *infloat, t_flag flagz);
char			*get_float(t_flag flagz, VL ap);

char			*malloc_str_c(t_flag flagz, VL ap, char option);
char			*malloc_str_s(t_flag flagz, VL ap);
char			*malloc_str_xp(t_flag flagz, VL ap);
char			*malloc_str_ou(t_flag flagz, VL ap);
char			*malloc_str_d(t_flag flagz, VL ap);

char			*fill_str_d(t_flag flagz, size_t lmax, char **toa, char *res);
char			*fill_str_ou(t_flag flagz, size_t lmax, char **toa, char *res);
char			*fill_str_xp(t_flag flagz, size_t lmax, char **toa, char *res);
char			*fill_str_s(t_flag flagz, size_t lmax, char *toa, char *res);
char			*fill_nomin_xp(t_flag flagz, size_t l_nb, char *res, size_t *c);

long long		check_d_i_flagz(t_flag flagz, VL ap);
ULL				check_poux_flagz(t_flag flagz, VL ap);
LD				check_f_flagz(t_flag flagz, VL ap);

#endif
