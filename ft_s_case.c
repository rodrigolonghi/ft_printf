/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:29:56 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/14 19:29:18 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_case(char *arg, int *chars)
{
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		chars[0] += 6;
	}
	else
	{
		ft_putstr_fd(arg, 1);
		chars[0] += ft_strlen(arg);
	}
}
