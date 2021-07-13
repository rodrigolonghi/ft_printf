/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:51:43 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/13 19:58:29 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_set_number(unsigned int n, int column)
{
	char	number;

	number = 'x';
	if (!(n == 0 && column != 0))
		number = n % 10 + '0';
	return (number);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	digit[11];
	int		column;
	int		printed;

	column = 0;
	printed = 0;
	while (column < 10)
	{
		digit[column] = ft_set_number(n, column);
		n /= 10;
		column++;
	}
	column = 9;
	while (column >= 0)
	{
		if (digit[column] != 'x')
		{
			ft_putchar_fd(digit[column], fd);
			printed++;
		}
		column--;
	}
	return (printed);
}
