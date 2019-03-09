/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:37:23 by fhagrave          #+#    #+#             */
/*   Updated: 2019/02/01 17:37:23 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct	s_gnl_list
{
	char				*content;
	int					fd;
	int					ret;
	struct s_gnl_list	*next;
}				t_gnl_list;

t_gnl_list		*ft_lstnew_gnl(const char *content, const int fd);
t_gnl_list		*multi_file_d(t_gnl_list	**r, const int fd);
int				get_next_line(const int fd, char **line);
int				part1(char buf[BUFF_SIZE + 1], char **temp, char **line,
				t_gnl_list **temp_list);
int				part2(char buf[BUFF_SIZE + 1], char **temp, char **line,
				t_gnl_list **temp_list);
#endif
