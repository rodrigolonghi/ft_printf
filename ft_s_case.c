/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:13:22 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/01 21:24:27 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_print_space(const char *str, int *chars, int start, char *arg)
{
	int	nbr;

	nbr = ft_atoi(ft_substr(str, start, ft_strlen(str) - 1));
	nbr -= ft_strlen(arg);
	while (nbr > 0)
	{
		ft_putchar_fd(' ', 1);
		nbr--;
		chars[0]++;
	}
	chars[1] += ft_strlen(str) - 2;
}

void static	ft_print_zero(const char *str, int *chars, int start, char *arg)
{
	int	nbr;

	nbr = ft_atoi(ft_substr(str, start, ft_strlen(str) - 2));
	nbr -= ft_strlen(arg);
	while (nbr > 0)
	{
		ft_putchar_fd('0', 1);
		nbr--;
		chars[0]++;
	}
	chars[1] += ft_strlen(str) - 1;
}

void static	ft_print_str(char *arg, int *chars)
{
	ft_putstr_fd(arg, 1);
	chars[0] += ft_strlen(arg);
	chars[1]++;
}

int	ft_s_case(const char *str, int pos, char *arg, int *chars)
{
	if (pos == 0)
		ft_print_str(arg, chars);
	else if (str[0] == '-')
	{
		ft_print_str(arg, chars);
		if (str[1] == '0')
			ft_print_zero(str, chars, 2, arg);
		else
			ft_print_space(str, chars, 1, arg);
	}
	else
	{
		if (str[0] == '0')
			ft_print_zero(str, chars, 1, arg);
		else
			ft_print_space(str, chars, 0, arg);
		ft_print_str(arg, chars);
	}
	return (1);
}
