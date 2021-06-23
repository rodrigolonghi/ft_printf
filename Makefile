# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 19:44:12 by rfelipe-          #+#    #+#              #
#    Updated: 2021/06/23 20:06:47 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = ft_printf.a

FT = ft_printf.o

all: $(NAME)

$(NAME) : $(FT)
	ar -rcs $(NAME) *.o

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
