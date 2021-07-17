/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:22:39 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/14 22:53:09 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_fill_nbr(char *nbr)
{
	int	pos;

	pos = 0;
	while (pos < 16)
	{
		nbr[pos] = 'f';
		pos++;
	}
}

void static	ft_print_adress(char *nbr, int *chars)
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
	free(nbr);
}

void	ft_p_case(unsigned long long int arg, int *chars)
{
	char	*hexadecimal_table;
	int		col;
	char	*nbr;

	col = 15;
	hexadecimal_table = "0123456789abcdef";
	nbr = ft_calloc(16, sizeof(char));
	ft_putstr_fd("0x", 1);
	chars[0] += 2;
	if (arg == 0)
		nbr[0] = '0';
	else if (arg < 0)
		ft_fill_nbr(nbr);
	else
	{
		while (arg != 0 && col >= 0)
		{
			nbr[col] = hexadecimal_table[arg % 16];
			arg /= 16;
			col--;
		}
	}
	ft_print_adress(nbr, chars);
}
