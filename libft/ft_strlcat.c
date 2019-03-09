/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:49:54 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 11:49:55 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_size);
	else if (size <= dst_size)
		return (size + src_size);
	else if (size > (dst_size + src_size))
		ft_strcat(dst, src);
	else
		ft_strncat(dst, src, size - dst_size - 1);
	return (src_size + dst_size);
}
