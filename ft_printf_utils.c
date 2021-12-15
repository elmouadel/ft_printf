/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:45:03 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/30 14:45:09 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr_ox(char *s)
{
	if (s[10] == 'A')
		write (1, "0X", 2);
	else
		write (1, "0x", 2);
	return (2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char	*dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

void	ft_putnbr_base(long nb, char *base, int *j, int p)
{
	int	len_base;

	if (nb == 0 && p > 0)
		return ;
	p = 0;
	len_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		(*j)++;
		ft_putnbr_base(-nb, base, j, p);
	}
	else if (nb >= len_base)
	{
		ft_putnbr_base(nb / len_base, base, j, p);
		ft_putnbr_base(nb % len_base, base, j, p);
	}
	else
		*j += ft_putchar(base[nb]);
}
