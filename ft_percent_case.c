/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:46:04 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/05 22:40:57 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_print_space(const char *str, int *chars, int start, int end)
{
	int	nbr;

	nbr = ft_atoi(ft_substr(str, start, end));
	while (nbr > 1)
	{
		ft_putchar_fd(' ', 1);
		nbr--;
		chars[0]++;
	}
	chars[1] += end;
}

void static	ft_print_zero(const char *str, int *chars, int start, int end)
{
	int	nbr;

	nbr = ft_atoi(ft_substr(str, start, end));
	while (nbr > 1)
	{
		ft_putchar_fd('0', 1);
		nbr--;
		chars[0]++;
	}
	chars[1] += end + 1;
}

void static	ft_print_char(int *chars)
{
	ft_putchar_fd('%', 1);
	chars[0]++;
	chars[1]++;
}

int	ft_percent_case(const char *str, int pos, int *chars)
{
	if (pos == 0)
		ft_print_char(chars);
	else if (str[0] == '-')
	{
		ft_print_char(chars);
		if (str[1] == '0')
			ft_print_space(str, chars, 2, pos);
		else
			ft_print_space(str, chars, 1, pos);
	}
	else
	{
		if (str[0] == '0')
			ft_print_zero(str, chars, 1, pos - 1);
		else
			ft_print_space(str, chars, 0, pos);
		ft_print_char(chars);
	}
	return (1);
}