/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:19:42 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 11:19:42 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size_to_find;
	size_t	i;
	size_t	j;
	char	*h;

	i = 0;
	j = 0;
	size_to_find = ft_strlen(needle);
	h = (char *)haystack;
	if (!size_to_find)
		return (h);
	while (*(h + i) != '\0')
	{
		while (*(h + i + j) == *(needle + j))
		{
			if (j == size_to_find - 1)
				return (h + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
