/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:43:12 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/30 14:43:18 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	g_sflag = {
	.minus = 0,
	.zero = 0,
	.plus = 0,
	.space = 0,
	.width = 0,
	.point = 0,
	.percision = 0,
};

void	ft_init_flags(void)
{
	g_sflag.minus = 0;
	g_sflag.zero = 0;
	g_sflag.plus = 0;
	g_sflag.space = 0;
	g_sflag.width = 0;
	g_sflag.point = 0;
	g_sflag.percision = 0;
}

void	ft_check_flags_str(const char *cc)
{
	int	i;

	i = 0;
	ft_init_flags();
	while (cc[i] == '0' || (!isdig(cc[i]) && !isalp(cc[i]) && cc[i] != '.'))
	{
		if (cc[i] == '0')
			g_sflag.zero = 1;
		else if (cc[i] == '-')
			g_sflag.minus = 1;
		else if (cc[i] == '+')
			g_sflag.plus = 1;
		else if (cc[i] == ' ')
			g_sflag.space = 1;
		i++;
	}
	while (isdig(cc[i]))
		g_sflag.width = (g_sflag.width * 10) + (cc[i++] - '0');
	if (cc[i] == '.' && i++ >= 0 && g_sflag.point++ >= 0)
		while (isdig(cc[i]))
				g_sflag.percision = (g_sflag.percision * 10) + (cc[i++] - '0');
}

void	ft_put_width_str(char c, int l_nb, int *j)
{
	int	h_per;

	h_per = g_sflag.percision;
	if (h_per > l_nb || !g_sflag.point)
		h_per = l_nb;
	while (h_per < g_sflag.width && h_per++ >= 0)
		(*j) += ft_putchar(c);
}

void	ft_putstr_str(char *str, int *j, const char *cc)
{
	int	i;
	int	h_perc;

	i = 0;
	if (!str)
		str = "(null)";
	ft_check_flags_str(cc);
	if (!g_sflag.minus)
		ft_put_width_str(' ', ft_strlen(str), j);
	h_perc = g_sflag.percision;
	if (!g_sflag.point)
		h_perc = ft_strlen(str);
	while (str[i] && i < h_perc)
	{
		write(1, &str[i], 1);
		(*j)++;
		i++;
	}
	if (g_sflag.minus)
		ft_put_width_str(' ', ft_strlen(str), j);
}
