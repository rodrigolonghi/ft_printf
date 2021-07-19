/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:22:39 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/19 02:34:52 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_adress(char *nbr, int *chars)
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
	free(nbr);
}
