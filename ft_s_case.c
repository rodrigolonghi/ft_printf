/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:13:22 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/08 23:10:51 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	ft_print_space(int nspaces, int ndot, int arglen, int *chars)
{
	int	limit;

	if (ndot == -1 || arglen < ndot)
		limit = nspaces - arglen;
	else
		limit = nspaces - ndot;
	while (limit > 0)
	{
		ft_putchar_fd(' ', 1);
		chars[0]++;
		limit--;
	}
}

void static	ft_print_str(char *arg, int *chars, int nbr)
{
	int	pos;

	pos = 0;
	if (nbr == -1)
		nbr = ft_strlen(arg);
	while (arg[pos] && nbr > 0)
	{
		ft_putchar_fd(arg[pos], 1);
		pos++;
		nbr--;
		chars[0]++;
	}
	chars[1]++;
}

int	ft_s_case(const char *str, int pos, char *arg, int *chars)
{
	if (pos == 0)
		ft_print_str(arg, chars, ft_strlen(arg));
	else
	{
		if (str[0] == '-')
		{
			ft_print_str(arg, chars, ft_find_nbr(ft_strchr(str, '.')));
			ft_print_space(ft_find_nbr(str),
				ft_find_nbr(ft_strchr(str, '.')), ft_strlen(arg), chars);
		}
		else
		{
			ft_print_space(ft_find_nbr(str),
				ft_find_nbr(ft_strchr(str, '.')), ft_strlen(arg), chars);
			ft_print_str(arg, chars, ft_find_nbr(ft_strchr(str, '.')));
		}
		chars[1] += pos;
	}
	return (1);
}

// str
// s		->		s
// 10s		->		10s
// -10s		->		-10s
// .2s		->		.2s
// 10.2s	->		10.2s
// -10.2s	->		-10.2s

// pos => str[pos] == s

// arg == "teste"

// chars:
// chars[0] = o quanto já foi impresso
// chars[1] = o quanto precisa andar com o str
