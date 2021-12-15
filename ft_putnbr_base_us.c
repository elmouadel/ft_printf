/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_us.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:55:49 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/29 17:21:01 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	g_uflag = {
	.minus = 0,
	.zero = 0,
	.plus = 0,
	.space = 0,
	.width = 0,
	.point = 0,
	.percision = 0,
};

void	ft_init_flags_us(void)
{
	g_uflag.minus = 0;
	g_uflag.zero = 0;
	g_uflag.plus = 0;
	g_uflag.space = 0;
	g_uflag.width = 0;
	g_uflag.point = 0;
	g_uflag.percision = 0;
}

void	ft_check_flags_us(const char *cc)
{
	int	i;

	i = 0;
	ft_init_flags_us();
	while (cc[i] == '0' || (!isdig(cc[i]) && !isalp(cc[i]) && cc[i] != '.'))
	{
		if (cc[i] == '0')
			g_uflag.zero = 1;
		else if (cc[i] == '-')
			g_uflag.minus = 1;
		else if (cc[i] == '+')
			g_uflag.plus = 1;
		else if (cc[i] == ' ')
			g_uflag.space = 1;
		i++;
	}
	while (isdig(cc[i]))
		g_uflag.width = (g_uflag.width * 10) + (cc[i++] - '0');
	if (cc[i] == '.' && i++ >= 0 && g_uflag.point++ >= 0)
		while (isdig(cc[i]))
				g_uflag.percision = (g_uflag.percision * 10) + (cc[i++] - '0');
}

void	ft_put_width_us(char c, int l_nb, int *j)
{
	int	h_per;

	h_per = g_uflag.percision;
	if (h_per < l_nb)
		h_per = l_nb;
	if (!g_uflag.point && g_uflag.zero && !g_uflag.minus)
		c = '0';
	if ((g_uflag.plus || g_uflag.space) && g_uflag.percision >= l_nb)
		h_per++;
	while (h_per < g_uflag.width && h_per++ >= 0)
		(*j) += ft_putchar(c);
}

int	ft_len_unb(long nb)
{
	int	i;

	i = 1;
	if (nb == 0 && g_uflag.point && !g_uflag.percision)
		return (0);
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_base_us(unsigned int nb, char *base, int *j, const char *cc)
{
	int	l_nb;

	ft_check_flags_us(cc);
	l_nb = ft_len_unb(nb);
	if (g_uflag.minus)
	{
		while (g_uflag.percision > l_nb && l_nb++ >= 0)
			(*j) += ft_putchar('0');
		ft_putnbr_base(nb, base, j, g_uflag.point - g_uflag.percision);
		ft_put_width_us(' ', ft_len_unb(nb), j);
	}
	else if (!g_uflag.minus)
	{
		ft_put_width_us(' ', ft_len_unb(nb), j);
		while (g_uflag.percision > l_nb && l_nb++ >= 0)
			(*j) += ft_putchar('0');
		ft_putnbr_base(nb, base, j, g_uflag.point - g_uflag.percision);
	}
}
