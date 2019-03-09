/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:25:34 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 12:25:35 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	t = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i++ < n)
		*(t++) = *(s++);
	return (dst);
}
