/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:51:53 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/14 19:00:58 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_call_functions(const char *str, va_list arg, int *chars)
{
	if (*str == 'c')
		ft_c_case(va_arg(arg, int), chars);
	else if (*str == '%')
		ft_percent_case(chars);
	else if (*str == 's')
		ft_s_case(va_arg(arg, char *), chars);
	else if (*str == 'd' || *str == 'i')
		ft_d_case(va_arg(arg, int), chars);
	else if (*str == 'u')
		ft_u_case(va_arg(arg, unsigned int), chars);
	else if (*str == 'p')
		ft_p_case(va_arg(arg, long long int), chars);
	else if (*str == 'x')
		ft_x_case(va_arg(arg, unsigned int), chars, 0);
	else if (*str == 'X')
		ft_x_case(va_arg(arg, unsigned int), chars, 1);
	chars[1]++;
}

int	ft_printf(const char *str, ...)
{
	int		*chars;
	int		result;
	va_list	arg;

	va_start(arg, str);
	chars = ft_calloc(2, sizeof(int));
	while (str[chars[1]] != '\0')
	{
		if (str[chars[1]] == '%')
			ft_call_functions(str + chars[1] + 1, arg, chars);
		else
		{
			ft_putchar_fd(str[chars[1]], 1);
			chars[0]++;
		}
		chars[1]++;
	}
	va_end(arg);
	result = chars[0];
	free(chars);
	return (result);
}
