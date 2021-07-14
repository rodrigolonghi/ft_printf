/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:22:39 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/13 22:27:30 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_p_case(long long int arg, int *chars)
{
	char	*hexadecimal_table;
	int		col;
	char	*nbr;

	col = 8;
	hexadecimal_table = "0123456789abcdef";
	nbr = ft_calloc(9, sizeof(char));
	ft_putstr_fd("0x", 1);
	chars[0] += 2;
	while (arg != 0)
	{
		nbr[col] = hexadecimal_table[arg % 16];
		arg /= 16;
		col--;
	}
	col = 0;
	while (col < 9)
	{
		if (nbr[col] != '\0')
			ft_putchar_fd(nbr[col], 1);
		col++;
		chars[0]++;
	}
}
