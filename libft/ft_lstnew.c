/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:55:55 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/23 16:55:56 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			tmp->content = (void *)malloc(content_size);
			if (!tmp->content)
				return (NULL);
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
