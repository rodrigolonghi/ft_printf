/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:51:53 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/01 19:37:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_call_functions(const char *str, va_list arg, int *chars, int pos)
{
	if (str[pos] == 'c')
		return (ft_c_case(str, pos, va_arg(arg, int), chars));
	else if (str[pos] == '%')
		return (ft_c_case(str, pos, '%', chars));
	else if (str[pos] == 's')
		return (ft_s_case(str, pos, va_arg(arg, char *), chars));
	else if (str[pos] == 'p')
		return (ft_p_case(str, pos, va_arg(arg, void *)));
	else if (str[pos] == 'd')
		return (ft_d_case(str, pos, va_arg(arg, int)));
	else if (str[pos] == 'i')
		return (ft_i_case(str, pos, va_arg(arg, void *)));
	else if (str[pos] == 'u')
		return (ft_u_case(str, pos, va_arg(arg, unsigned int)));
	else if (str[pos] == 'x')
		return (ft_x_case(str, pos, va_arg(arg, void *)));
	else if (str[pos] == 'X')
		return (ft_X_case(str, pos, va_arg(arg, void *)));
	return (0);
}

void static	ft_check_args(const char *str, va_list arg, int *chars)
{
	int	pos;
	int	control;

	pos = 0;
	control = 0;
	while (str[pos] && control == 0)
	{
		control = ft_call_functions(str, arg, chars, pos);
		pos++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		*chars;
	va_list	arg;

	va_start(arg, str);
	chars = ft_calloc(2, sizeof(int));
	while (str[chars[1]] != '\0')
	{
		if (str[chars[1]] == '%')
			ft_check_args(str + chars[1] + 1, arg, chars);
		else
		{
			ft_putchar_fd(str[chars[1]], 1);
			chars[0]++;
		}
		chars[1]++;
	}
	va_end(arg);
	return (chars[0]);
}
