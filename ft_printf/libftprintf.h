/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:22:54 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/07/07 18:33:56 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

# define SPACE (1)
# define HASH (1 << 1)
# define ZERO (1 << 2)
# define MINUS (1 << 3)
# define PLUS (1 << 4)
# define MAXI(a,b) ((a) > (b) ? (a) : (b))
# define MIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct		s_fo{
	char			fl;
	long			w;
	long			p;
	int				l;
}					t_fo;

typedef struct		s_type{
	char			c;
	void			(*f)(va_list a, t_fo b, int *c);
}					t_type;

typedef struct		s_stc{
	int				n;
	char			*string;
}					t_stc;

typedef struct		s_dec{
	t_stc			s;
	long long		i;
	int				ad;
	int				m;
	int				start;
	int				count;
	char			c;
	char			e;
}					t_dec;

typedef struct		s_sh{
	int				c;
	int				h;
	char			*string;
}					t_sh;

typedef	struct		s_node{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

typedef	struct		s_float{
	unsigned long	fract :52;
	unsigned long	e :11;
	unsigned long	sign :1;
}					t_float;

typedef	union{
	double			f;
	t_float			sf;
}					t_myfloat;

typedef struct		s_long{
	unsigned long	fract :64;
	unsigned long	e :15;
	unsigned long	s :1;
}					t_long;

typedef union{
	long double		var;
	t_long			ld;
}					t_ldouble;

typedef struct		s_n{
	va_list			ap;
	t_type			t[11];
	t_fo			str;
	int				i;
	int				re;
	char			*format;
}					t_n;

int					ft_printf(const char *test, ...);
void				ft_help(char c, int *r);
void				ft_int(t_type *t);
t_fo				ft_struct(char **format, va_list ap);
long				ft_pres(char **format, va_list ap);
int					ft_len(char **format);
int					ft_len1(char c);
int					ft_width(char **format, va_list ap, char *fl);
char				ft_flags(char **format);
int					ft_num(char c);
int					ft_true(char s);
long				ft_atl(const char *str);
void				c_string(va_list ap, t_fo str, int *res);
void				test_string(va_list ap, t_fo str, int *re);
long long			ft_num2(va_list ap, int i);
t_stc				ft_gets(long long i, t_fo str);
t_dec				ft_dec(va_list ap, t_fo str, int *re);
void				d_string(va_list ap, t_fo str, int *re);
void				o_string(va_list ap, t_fo str, int *re);
void				u_string(va_list ap, t_fo str, int *re);
void				ou_string(va_list ap, t_fo str, int *re, int base);
t_stc				t_tu(unsigned long long i, t_fo str, int base);
t_stc				t_tl(unsigned long long i, t_fo str, int base);
int					count(unsigned long long i, int base);
unsigned long long	ft_tyo(va_list ap, int i);
void				upx_string(va_list ap, t_fo str, int *re);
void				x_string(va_list ap, t_fo str, int *re);
void				hex(va_list ap, t_fo str, int *re, char *b);
void				heupx(va_list ap, t_fo str, int *re, char *b);
t_sh				shex(unsigned long long i, t_fo str, char *b, char *join);
t_sh				nz(unsigned long long i, t_fo str, char *b, char *join);
void				p_string(va_list ap, t_fo str, int *re);
void				ft_notzeo(unsigned long long i, t_fo str, int *re);
void				onlyzero(t_fo str, int *re);
void				f_string(va_list ap, t_fo str, int *re);
void				fl_limits(char *string, int l, t_fo str, int *re);
void				fl_inf(char *string, t_fo str, int *re, int sign);
void				addnode(t_node **node1, t_node *node2);
void				ft_print(t_node *res);
void				nodefree(t_node *res);
t_node				*newnode(int data);
int					fn(t_node *node);
t_node				*ft_fracnode(unsigned long i, int e);
t_node				*ad(t_node *res, t_node *base, int l, int m);
void				ft_norm(t_node **node, int *carry, int j);
t_node				*ft_base(int e);
void				ft_mul(t_node **base);
t_node				*ft_inte(unsigned long i, int e, int carry);
void				nodemul(t_node **base, int i);
t_node				*nodeadd(t_node *node1, t_node *node2);
void				ft_data(t_node **r, t_node **n, t_node **n2, int *c);
void				ft_dataf(t_node **r, t_node **n1, t_node **n2, int *c);
int					ft_after(t_node *res, int prev);
int					ft_prec(t_node **res);
int					ft_round(int data, int prev);
int					ft_car(t_node *res, long p);
t_node				*end(int j);
int					ft_printflag(t_node **fl, t_fo t, int s);
void				ft_printall(t_node **floa, t_fo str);
void				ft_zero(int *e, int i);
void				double_str(va_list ap, t_fo str, int *re);
void				fl_string(t_float f, t_fo str, int *re);
t_node				**floatnode(t_float f, long p);
unsigned long		*dl(t_float *f, int *ex);
unsigned long		ft_shift(unsigned long m, int e);
void				long_str(va_list ap, t_fo str, int *re);
void				getlong(t_long l, t_fo str, int *re);
t_node				**getnode(t_long l, int p);
unsigned long		*ft_getl(t_long l, int *e, int *k);
void				ft_nan(char *s, int *re);
void				ptg(va_list ap, t_fo str, int *re);
void				*ft_malloc(size_t size);
#endif
