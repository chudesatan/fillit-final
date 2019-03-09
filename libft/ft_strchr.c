/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:14:54 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 12:14:55 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	ptr;

	str = (char *)s;
	ptr = 0;
	if (c != '\0')
	{
		while (*(str + ptr) != '\0')
		{
			if (*(str + ptr) == (char)c)
				return (str + ptr);
			ptr++;
		}
	}
	else
	{
		while (1)
		{
			if (*(str + ptr) == (char)c)
				return (str + ptr);
			ptr++;
		}
	}
	return (NULL);
}
