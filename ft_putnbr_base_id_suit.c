/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_id_suit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:20:35 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/30 11:42:16 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	isdig(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	isalp(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}

void	ft_put_res_nb(long nb, char *base, int *j, int p)
{
	int	len_base;

	if (nb == 0 && p > 0)
		return ;
	p = 0;
	len_base = ft_strlen(base);
	if (nb < 0)
		nb = -nb;
	if (nb >= len_base)
	{
		ft_put_res_nb(nb / len_base, base, j, p);
		ft_put_res_nb(nb % len_base, base, j, p);
	}
	else
		*j += ft_putchar(base[nb]);
}
