/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:29:52 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 12:29:53 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*temp;

	if (size)
	{
		temp = (char*)malloc(sizeof(*temp) * (int)size);
		if (!temp)
			return (NULL);
		while (size-- != 0)
			temp[size] = 0;
		return ((void *)temp);
	}
	return (NULL);
}
