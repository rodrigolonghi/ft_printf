/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:10:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/08 23:46:00 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_print_space(const char *str, int *chars, int nbr)
{
	if (nbr == -2)
		nbr = ft_find_nbr(str) - 1;
	while (nbr > 0)
	{
		ft_putchar_fd(' ', 1);
		nbr--;
		chars[0]++;
	}
}

void static	ft_print_char(unsigned char c, int *chars)
{
	ft_putchar_fd(c, 1);
	chars[0]++;
}

int	ft_c_case(const char *str, int pos, va_list arg, int *chars)
{
	unsigned char	c;
	int				width;

	width = -1;
	if (ft_strchr(str, '*'))
		width = va_arg(arg, int);
	c = (unsigned char) va_arg(arg, int);
	if (pos == 0)
		ft_print_char(c, chars);
	else
	{
		if (str[0] == '-')
		{
			ft_print_char(c, chars);
			ft_print_space(str, chars, width - 1);
		}
		else
		{
			ft_print_space(str, chars, width - 1);
			ft_print_char(c, chars);
		}
	}
	return (1);
}
