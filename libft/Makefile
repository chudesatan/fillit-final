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

NAME = libft.a
SRC = ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr.c ft_putendl.c ft_putstr.c ft_putchar.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strequ.c ft_strnequ.c ft_strmap.c ft_strmapi.c ft_striter.c ft_striteri.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c ft_memalloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_atoi.c ft_strcmp.c ft_strncmp.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_strlen.c ft_strcpy.c ft_memcmp.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strlcat.c ft_strdup.c ft_strnstr.c
OBJS = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I.
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
