/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:26:41 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 12:26:50 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*s;

	i = 0;
	t = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i++ < n)
	{
		if (*(t++) != *(s++))
			return (*(t - 1) - *(s - 1));
	}
	return (0);
}
