/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:28:47 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 12:28:48 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*s;
	unsigned char	symb;

	i = 0;
	t = (unsigned char *)dst;
	s = (unsigned char *)src;
	symb = (unsigned char)c;
	while (i++ < n)
	{
		*(t++) = *(s++);
		if (*(t - 1) == symb)
			return (t);
	}
	return (NULL);
}
