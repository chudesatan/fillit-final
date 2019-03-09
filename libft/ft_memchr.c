/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:27:39 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 12:27:40 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	symb;

	i = 0;
	t = (unsigned char *)s;
	symb = (unsigned char)c;
	while (i++ < n)
	{
		if (*(t++) == symb)
			return (t - 1);
	}
	return (NULL);
}
