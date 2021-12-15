/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:53:21 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/30 13:11:53 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	width;
	int	point;
	int	percision;
}	t_flags;

int		ft_printf(const char *str, ...);

void	ft_putchar_cs(char c, int *j, const char *cc);
void	ft_putstr_str(char *str, int *j, const char *cc);
void	ft_put_add(va_list arg, int *j, const char *cc);
void	ft_putnbr_base_id(long nbr, char *base, int *j, const char *cc);
void	ft_putnbr_base_us(unsigned int nb, char *base, int *j, const char *cc);
void	ft_putnbr_base_hex(unsigned int nb, char *base, int *j, const char *cc);

int		isdig(int c);
int		isalp(int c);
void	ft_put_res_nb(long nb, char *base, int *j, int p);

char	*ft_strcpy(char	*dest, char *src);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr_ox(char *s);
void	ft_putnbr_base(long nbr, char *base, int *j, int p);

#endif
