/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:51:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/07/13 19:58:43 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_c_case(int arg, int *chars);
void	ft_percent_case(int *chars);
void	ft_s_case(char *arg, int *chars);
void	ft_d_case(int arg, int *chars);
int		ft_putunbr_fd(unsigned int n, int fd);
void	ft_u_case(unsigned int arg, int *chars);

#endif
