/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:31:15 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/29 17:04:21 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	g_cflag = {
	.minus = 0,
	.zero = 0,
	.plus = 0,
	.space = 0,
	.width = 0,
	.point = 0,
	.percision = 0,
};

void	ft_init_flags_cs(void)
{
	g_cflag.minus = 0;
	g_cflag.zero = 0;
	g_cflag.plus = 0;
	g_cflag.space = 0;
	g_cflag.width = 0;
	g_cflag.point = 0;
	g_cflag.percision = 0;
}

void	ft_check_flags_cs(const char *cc)
{
	int	i;

	i = 0;
	ft_init_flags_cs();
	while (cc[i] == '0' || (!isdig(cc[i]) && !isalp(cc[i]) && cc[i] != '.'))
	{
		if (cc[i] == '0')
			g_cflag.zero = 1;
		else if (cc[i] == '-')
			g_cflag.minus = 1;
		else if (cc[i] == '+')
			g_cflag.plus = 1;
		else if (cc[i] == ' ')
			g_cflag.space = 1;
		i++;
	}
	while (isdig(cc[i]))
		g_cflag.width = (g_cflag.width * 10) + (cc[i++] - '0');
	if (cc[i] == '.' && i++ >= 0 && g_cflag.point++ >= 0)
		while (isdig(cc[i]))
				g_cflag.percision = (g_cflag.percision * 10) + (cc[i++] - '0');
}

void	ft_putchar_cs(char c, int *j, const char *cc)
{
	ft_check_flags_cs(cc);
	if (!g_cflag.minus)
		while (--g_cflag.width > 0)
			(*j) += ft_putchar(' ');
	write (1, &c, 1);
	(*j)++;
	if (g_cflag.minus)
		while (--g_cflag.width > 0)
			(*j) += ft_putchar(' ');
}
