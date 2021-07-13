/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:12:39 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/13 19:25:40 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_case(int arg, int *chars)
{
	unsigned char	c;

	c = (unsigned char) arg;
	ft_putchar_fd(c, 1);
	chars[0]++;
}
