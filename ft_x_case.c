/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:34:48 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/13 22:55:15 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_case(unsigned int arg, int *chars, int uppercase)
{
	char	*hexadecimal_table;
	int		col;
	char	*nbr;

	col = 8;
	if (uppercase == 0)
		hexadecimal_table = "0123456789abcdef";
	else
		hexadecimal_table = "0123456789ABCDEF";
	nbr = ft_calloc(9, sizeof(char));
	while (arg != 0)
	{
		nbr[col] = hexadecimal_table[arg % 16];
		arg /= 16;
		col--;
	}
	col = 0;
	while (col++ < 9)
	{
		if (nbr[col - 1] != '\0')
		{
			ft_putchar_fd(nbr[col - 1], 1);
			chars[0]++;
		}
	}
}
