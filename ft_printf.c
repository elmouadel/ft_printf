/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:52:56 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/29 16:51:12 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	ft_is_conv(const char *c, int aut, int *o)
{
	char	conv[24];
	int		i;
	int		j;

	ft_strcpy(conv, "cspdiuxX-+. #0123456789");
	if (aut == 1)
		conv[8] = '\0';
	j = 0;
	while (c[j] && j >= 0)
	{
		i = 0;
		while (conv[i])
		{
			if (c[j] == conv[i])
				return (conv[i]);
			i++;
		}
		if (aut == 0)
			j = -3;
		j++;
		(*o)++;
	}
	return ('a');
}

void	ft_print_arg(const char *cc, va_list arg, int *i, int *j)
{
	char	c;
	char	base_d[11];
	char	base_x[17];
	char	base_ux[17];

	ft_strcpy(base_d, "0123456789\0");
	ft_strcpy(base_x, "0123456789abcdef\0");
	ft_strcpy(base_ux, "0123456789ABCDEF\0");
	c = ft_is_conv(cc, 1, i);
	if (c == 'c')
		ft_putchar_cs((char)va_arg(arg, int), j, cc);
	else if (c == 's')
		ft_putstr_str((char *)va_arg(arg, char *), j, cc);
	else if (c == 'p')
		ft_put_add(arg, j, cc);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base_id((int)va_arg(arg, int), base_d, j, cc);
	else if (c == 'u')
		ft_putnbr_base_us((unsigned)va_arg(arg, unsigned), base_d, j, cc);
	else if (c == 'x')
		ft_putnbr_base_hex((int)va_arg(arg, int), base_x, j, cc);
	else if (c == 'X')
		ft_putnbr_base_hex((int)va_arg(arg, int), base_ux, j, cc);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	va_start(arg, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%' && i++ >= 0)
		{
			if (ft_is_conv(&str[i], 0, &i) != 'a')
				ft_print_arg(&str[i], arg, &i, &j);
			else
				break ;
		}
		else if (str[i] != '%' || str[i + 1] != '%')
			j += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1] == '%' && i++ >= 0)
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (j);
}
