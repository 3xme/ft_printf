# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiari <abiari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 01:50:43 by abiari            #+#    #+#              #
#    Updated: 2019/11/20 04:26:37 by abiari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_convert.c ft_getflags.c ft_isdigit.c \
ft_printd.c ft_strchr.c ft_printu.c ft_printp.c ft_printx.c ft_prints.c \
ft_printc.c ft_print_perc.c ft_len.c ft_printd_utils.c ft_lenu.c ft_lenx.c \
ft_slen.c ft_prints_dash.c ft_printx_both.c ft_printu_utils.c

OBJ = $(SRC:.c=.o)
 
all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re