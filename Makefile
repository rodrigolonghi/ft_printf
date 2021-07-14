# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 19:44:12 by rfelipe-          #+#    #+#              #
#    Updated: 2021/07/13 22:36:51 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

FT = ft_printf.o \
	ft_c_case.o \
	ft_percent_case.o \
	ft_s_case.o \
	ft_d_case.o \
	ft_putunbr_fd.o \
	ft_u_case.o \
	ft_p_case.o \
	ft_x_case.o

all: $(NAME)

$(NAME) : $(FT)
	make bonus -C ./libft
	cp ./libft/libft.a ./$(NAME)
	ar -rcs $(NAME) *.o

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf *.o

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft
