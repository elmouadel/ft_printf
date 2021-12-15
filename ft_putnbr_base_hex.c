/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:39:09 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/30 11:41:52 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	g_xflag = {
	.minus = 0,
	.zero = 0,
	.plus = 0,
	.space = 0,
	.width = 0,
	.point = 0,
	.percision = 0,
};

void	ft_init_flags_hex(void)
{
	g_xflag.minus = 0;
	g_xflag.zero = 0;
	g_xflag.plus = 0;
	g_xflag.space = 0;
	g_xflag.width = 0;
	g_xflag.point = 0;
	g_xflag.percision = 0;
}

void	ft_check_flags_hex(const char *cc)
{
	int	i;

	i = 0;
	ft_init_flags_hex();
	while (cc[i] == '0' || (!isdig(cc[i]) && !isalp(cc[i]) && cc[i] != '.'))
	{
		if (cc[i] == '0')
			g_xflag.zero = 1;
		else if (cc[i] == '-')
			g_xflag.minus = 1;
		else if (cc[i] == '#')
			g_xflag.plus = 1;
		else if (cc[i] == ' ' || cc[i] == '+')
			g_xflag.space = 1;
		i++;
	}
	while (isdig(cc[i]))
		g_xflag.width = (g_xflag.width * 10) + (cc[i++] - '0');
	if (cc[i] == '.' && i++ >= 0 && g_xflag.point++ >= 0)
		while (isdig(cc[i]))
			g_xflag.percision = (g_xflag.percision * 10) + (cc[i++] - '0');
}

void	ft_put_width_hex(char c, int l_nb, int *j)
{
	int	h_per;

	h_per = g_xflag.percision;
	if (h_per < l_nb)
		h_per = l_nb;
	if (!g_xflag.point && g_xflag.zero && !g_xflag.minus)
		c = '0';
	if (g_xflag.plus)
		h_per += 2;
	while (h_per < g_xflag.width && h_per++ >= 0)
		(*j) += ft_putchar(c);
}

int	ft_len_hex(unsigned int nb)
{
	int	i;

	i = 1;
	if (nb == 0 && g_xflag.point)
		return (0);
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_base_hex(unsigned int nb, char *base, int *j, const char *cc)
{
	int	l_nb;

	ft_check_flags_hex(cc);
	l_nb = ft_len_hex(nb);
	if (nb == 0 && g_xflag.plus)
		g_xflag.plus = 0;
	else if (((g_xflag.zero && !g_xflag.point)
			|| g_xflag.minus) && g_xflag.plus)
		(*j) += ft_putstr_ox(base);
	if (g_xflag.minus)
	{
		while (g_xflag.percision > l_nb && l_nb++ >= 0)
			(*j) += ft_putchar('0');
		ft_putnbr_base(nb, base, j, g_xflag.point);
		ft_put_width_hex(' ', ft_len_hex(nb), j);
	}
	else if (!g_xflag.minus)
	{
		ft_put_width_hex(' ', ft_len_hex(nb), j);
		if ((!g_xflag.zero || g_xflag.point) && g_xflag.plus && nb != 0)
			(*j) += ft_putstr_ox(base);
		while (g_xflag.percision > l_nb && l_nb++ >= 0)
			(*j) += ft_putchar('0');
		ft_putnbr_base(nb, base, j, g_xflag.point);
	}
}
