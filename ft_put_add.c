/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:44:41 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/30 14:44:46 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	g_pflag = {
	.minus = 0,
	.zero = 0,
	.plus = 0,
	.space = 0,
	.width = 0,
	.point = 0,
	.percision = 0,
};

void	ft_init_flags_ps(void)
{
	g_pflag.minus = 0;
	g_pflag.zero = 0;
	g_pflag.plus = 0;
	g_pflag.space = 0;
	g_pflag.width = 0;
	g_pflag.point = 0;
	g_pflag.percision = 0;
}

void	ft_check_flags_ps(const char *cc)
{
	int	i;

	i = 0;
	ft_init_flags_ps();
	while (cc[i] == '0' || (!isdig(cc[i]) && !isalp(cc[i]) && cc[i] != '.'))
	{
		if (cc[i] == '0')
			g_pflag.zero = 1;
		else if (cc[i] == '-')
			g_pflag.minus = 1;
		else if (cc[i] == '+')
			g_pflag.plus = 1;
		else if (cc[i] == ' ')
			g_pflag.space = 1;
		i++;
	}
	while (isdig(cc[i]))
		g_pflag.width = (g_pflag.width * 10) + (cc[i++] - '0');
	if (cc[i] == '.' && i++ >= 0 && g_pflag.point++ >= 0)
		while (isdig(cc[i]))
				g_pflag.percision = (g_pflag.percision * 10) + (cc[i++] - '0');
}

void	ft_put_p_hex(unsigned long nb, char *base, int *j)
{
	if (nb >= 16)
	{
		ft_put_p_hex(nb / 16, base, j);
		ft_put_p_hex(nb % 16, base, j);
	}
	else
		*j += ft_putchar(base[nb]);
}

int	ft_len_hp(unsigned long hp)
{
	int	i;

	i = 1;
	if (hp == 0 && g_pflag.point)
		return (0);
	while (hp > 15)
	{
		hp = hp / 16;
		i++;
	}
	return (i);
}

void	ft_put_add(va_list arg, int *j, const char *cc)
{
	int				h_width;
	void			*p;
	unsigned long	hp;

	p = va_arg(arg, void *);
	hp = (unsigned long)p;
	ft_check_flags_ps(cc);
	h_width = g_pflag.width - ft_len_hp(hp) - 2;
	if (!g_pflag.minus)
		while (h_width-- > 0)
			(*j) += ft_putchar(' ');
	(*j) += ft_putstr_ox("0x");
	if (hp != 0 || (hp == 0 && !g_pflag.point))
		ft_put_p_hex(hp, "0123456789abcdef", j);
	if (g_pflag.minus)
		while (h_width-- > 0)
			(*j) += ft_putchar(' ');
}
