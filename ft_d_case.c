/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:37:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/14 21:36:54 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_case(int arg, int *chars)
{
	char	*nbr;

	nbr = ft_itoa(arg);
	ft_putstr_fd(nbr, 1);
	chars[0] += ft_strlen(nbr);
	free(nbr);
}
