/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:15:21 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/29 17:15:40 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	g_iflag = {
	.minus = 0,
	.zero = 0,
	.plus = 0,
	.space = 0,
	.width = 0,
	.point = 0,
	.percision = 0,
};

int	ft_len_nbr(long nb)
{
	int	i;

	i = 1;
	if ((g_iflag.plus || g_iflag.space) && nb >= 0)
		i++;
	if (nb < 0)
	{
		g_iflag.plus = 1;
		nb = -nb;
		i++;
	}
	if (nb == 0 && g_iflag.point && !g_iflag.percision)
		return (0);
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_put_width(char c, int l_nb, int *j, int aut)
{
	int	h_per;

	if (aut == -1)
	{
		g_iflag.minus = 0;
		g_iflag.zero = 0;
		g_iflag.plus = 0;
		g_iflag.space = 0;
		g_iflag.width = 0;
		g_iflag.point = 0;
		g_iflag.percision = 0;
	}
	else
	{
		h_per = g_iflag.percision;
		if (h_per < l_nb)
			h_per = l_nb;
		if (!g_iflag.point && g_iflag.zero && !g_iflag.minus)
			c = '0';
		if ((g_iflag.plus || g_iflag.space) && g_iflag.percision >= l_nb)
			h_per++;
		while (h_per < g_iflag.width && h_per++ >= 0)
			(*j) += ft_putchar(c);
	}
}

void	ft_check_flags(const char *cc)
{
	int	i;

	i = 0;
	ft_put_width(' ', 0, NULL, -1);
	while (cc[i] == '0' || (!isdig(cc[i]) && !isalp(cc[i]) && cc[i] != '.'))
	{
		if (cc[i] == '0')
			g_iflag.zero = 1;
		else if (cc[i] == '-')
			g_iflag.minus = 1;
		else if (cc[i] == '+')
			g_iflag.plus = 1;
		else if (cc[i] == ' ')
			g_iflag.space = 1;
		i++;
	}
	while (isdig(cc[i]))
		g_iflag.width = (g_iflag.width * 10) + (cc[i++] - '0');
	if (cc[i] == '.' && i++ >= 0 && g_iflag.point++ >= 0)
		while (isdig(cc[i]))
				g_iflag.percision = (g_iflag.percision * 10) + (cc[i++] - '0');
}

void	ft_print_sig(long nb, int *j)
{
	if ((g_iflag.plus || g_iflag.space) && nb >= 0)
	{
		if (g_iflag.space > g_iflag.plus)
			(*j) += ft_putchar(' ');
		else
			(*j) += ft_putchar('+');
	}
	if (nb < 0)
	{
		(*j) += ft_putchar('-');
		nb = -nb;
	}
}

void	ft_putnbr_base_id(long nb, char *base, int *j, const char *cc)
{
	int	l_nb;

	ft_check_flags(cc);
	l_nb = ft_len_nbr(nb);
	if (g_iflag.plus || g_iflag.space)
			l_nb--;
	if (g_iflag.minus)
	{
		ft_print_sig(nb, j);
		while (g_iflag.percision > l_nb && l_nb++ >= 0)
			(*j) += ft_putchar('0');
		ft_put_res_nb(nb, base, j, g_iflag.point - g_iflag.percision);
		ft_put_width(' ', ft_len_nbr(nb), j, 1);
	}
	else if (!g_iflag.minus)
	{
		if (g_iflag.zero && !g_iflag.point)
			ft_print_sig(nb, j);
		ft_put_width(' ', ft_len_nbr(nb), j, 1);
		if (!g_iflag.zero || g_iflag.point)
			ft_print_sig(nb, j);
		while (g_iflag.percision > l_nb && l_nb++ >= 0)
			(*j) += ft_putchar('0');
		ft_put_res_nb(nb, base, j, g_iflag.point - g_iflag.percision);
	}
}
