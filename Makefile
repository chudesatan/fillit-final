#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 14:27:09 by fhagrave          #+#    #+#              #
#    Updated: 2018/12/11 14:27:10 by fhagrave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = *.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc -Wall -Wextra -Werror main.c get_next_line.c add_tetra.c check.c print_read.c solve.c tetra_pos.c valid_tetra.c -I libft/ -L. libft/libft.a -o fillit

clean:
	rm -f $(OBJS) libft/*.o

fclean: clean
	rm -f fillit
	rm -f libft/libft.a

re: fclean all
