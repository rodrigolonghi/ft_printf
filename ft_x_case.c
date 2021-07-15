/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:34:48 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/14 21:46:33 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_print_nbr(char *nbr, int *chars)
{
	int	col;

	col = 0;
	while (col < 16)
	{
		if (nbr[col] != '\0')
		{
			ft_putchar_fd(nbr[col], 1);
			chars[0]++;
		}
		col++;
	}
}

void	ft_x_case(unsigned int arg, int *chars, int uppercase)
{
	char	*hexadecimal_table;
	int		col;
	char	*nbr;

	col = 15;
	if (uppercase == 0)
		hexadecimal_table = "0123456789abcdef";
	else
		hexadecimal_table = "0123456789ABCDEF";
	nbr = ft_calloc(16, sizeof(char));
	if (arg == 0)
		nbr[0] = '0';
	else
	{
		while (arg != 0 && col >= 0)
		{
			nbr[col] = hexadecimal_table[arg % 16];
			arg /= 16;
			col--;
		}
	}
	ft_print_nbr(nbr, chars);
	free(nbr);
}
