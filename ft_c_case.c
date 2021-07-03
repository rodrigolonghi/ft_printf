/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:10:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/03 16:21:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_print_space(const char *str, int *chars, int start, int end)
{
	int	nbr;

	nbr = ft_atoi(ft_substr(str, start, end));
	while (nbr > 1)
	{
		ft_putchar_fd(' ', 1);
		nbr--;
		chars[0]++;
	}
	chars[1] += end;
}

void static	ft_print_char(unsigned char c, int *chars)
{
	ft_putchar_fd(c, 1);
	chars[0]++;
	chars[1]++;
}

int	ft_c_case(const char *str, int pos, int arg, int *chars)
{
	unsigned char	c;

	c = (unsigned char)arg;
	if (pos == 0)
		ft_print_char(c, chars);
	else if (str[0] == '-')
	{
		ft_print_char(c, chars);
		ft_print_space(str, chars, 1, pos);
	}
	else
	{
		ft_print_space(str, chars, 0, pos);
		ft_print_char(c, chars);
	}
	return (1);
}
