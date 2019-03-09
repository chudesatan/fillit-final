/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:45:16 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 11:45:17 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s1);
	if (n >= ft_strlen(s2))
		ft_strcpy(s1 + size, s2);
	else
	{
		i = 0;
		while (i < n)
		{
			*(s1 + size + i) = *(s2 + i);
			i++;
		}
		*(s1 + size + i) = '\0';
	}
	return (s1);
}
