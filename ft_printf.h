/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:51:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/08 23:48:41 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_find_nbr(const char *str);
int	ft_printf(const char *str, ...);
int	ft_c_case(const char *str, int pos, va_list arg, int *chars);
int	ft_percent_case(const char *str, int pos, int *chars);
int	ft_s_case(const char *str, int pos, char *arg, int *chars);

#endif
