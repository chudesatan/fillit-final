/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:36:48 by fhagrave          #+#    #+#             */
/*   Updated: 2019/02/01 17:36:49 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*ft_ext_lstnew(void const *content, const int fd)
{
	t_gnl_list	*tmp;

	if ((tmp = (t_gnl_list*)malloc(sizeof(t_gnl_list))) == NULL)
		return (NULL);
	tmp->content = (char *)malloc(BUFF_SIZE + 1);
	if (!tmp->content)
		return (NULL);
	ft_strcpy(tmp->content, content);
	tmp->fd = fd;
	tmp->ret = 1;
	tmp->next = NULL;
	return (tmp);
}

t_gnl_list	*multi_file_d(t_gnl_list **r, const int fd)
{
	t_gnl_list	*temp_list;

	if (*r == NULL)
		*r = ft_ext_lstnew("", fd);
	temp_list = *r;
	while (temp_list)
	{
		if (temp_list->fd == fd)
			break ;
		temp_list = temp_list->next;
	}
	if (temp_list == NULL)
	{
		temp_list = ft_ext_lstnew("", fd);
		temp_list->next = *r;
		*r = temp_list;
	}
	return (temp_list);
}

int			get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	char				*temp;
	static t_gnl_list	*r = NULL;
	t_gnl_list			*temp_list;

	if ((temp_list = multi_file_d(&r, fd)) == NULL ||
		fd < 0 || read(fd, buf, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	else if (temp_list->ret == 0)
		return (0);
	if (ft_strcmp(temp_list->content, "") == 0 && (temp = ""))
	{
		temp_list->ret = read(fd, buf, BUFF_SIZE);
		if (temp_list->ret == 0 && (temp_list->ret = 1))
			return (0);
		buf[temp_list->ret] = '\0';
		if ((temp = ft_strjoin(temp, buf)) == NULL)
			return (-1);
	}
	else
		temp = temp_list->content;
	if ((buf[0] = part1(buf, &temp, line, &temp_list)) == -2)
		free(temp);
	return (buf[0] == -2 ? -1 : buf[0]);
}

int			part1(char buf[BUFF_SIZE + 1], char **temp, char **line,
			t_gnl_list **temp_list)
{
	int	result;

	while ((*temp_list)->ret)
		if ((result = part2(buf, temp, line, temp_list)) == 1)
			break ;
		else if (result != 0)
			return (result);
	if ((*temp_list)->ret > 0)
		return (1);
	if ((*line = ft_strsub(*temp, 0, ft_strlen(*temp))) == NULL)
		return (-2);
	free(*temp);
	return (1);
}

int			part2(char buf[BUFF_SIZE + 1], char **temp, char **line,
			t_gnl_list **temp_list)
{
	char	*n_pointer;
	char	*temp_copy;

	if ((n_pointer = ft_strchr(*temp, '\n')) != NULL)
	{
		if ((*line = ft_strsub(*temp, 0, n_pointer - *temp)) == NULL)
			return (-2);
		if (*temp != ft_strcpy((*temp_list)->content, (n_pointer + 1)))
			free(*temp);
		return (1);
	}
	(*temp_list)->ret = read((*temp_list)->fd, buf, BUFF_SIZE);
	buf[(*temp_list)->ret] = '\0';
	temp_copy = *temp;
	if ((*temp = ft_strjoin(*temp, buf)) == NULL)
	{
		free(temp_copy);
		return (-1);
	}
	if (temp_copy != (*temp_list)->content)
		free(temp_copy);
	return (0);
}
