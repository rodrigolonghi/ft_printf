/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 23:08:39 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/08 23:32:42 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_nbr(const char *str)
{
	int	start;
	int	len;

	if (!str)
		return (-1);
	start = 0;
	if (str[0] == '-' || str[0] == '.')
		start++;
	len = 0;
	while (ft_isalpha(str[start]))
		start++;
	while (ft_isdigit(str[len + start]))
		len++;
	return (ft_atoi(ft_substr(str, start, len)));
}
