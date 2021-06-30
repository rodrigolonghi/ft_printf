/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:10:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/06/30 00:02:26 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_case(const char *str, int pos, int arg, int *chars)
{
	unsigned char	temp;

	temp = (unsigned char)arg;
	if (str[pos] == 'c')
	{
		ft_putchar_fd(temp, 1);
		chars[0]++;
		chars[1]++;
	}
}
