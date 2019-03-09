/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:04:18 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/15 20:04:19 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*temp;

	if (s != NULL)
	{
		temp = (char*)malloc(sizeof(*temp) * (int)(len + 1));
		if (!temp)
			return (NULL);
		temp[len] = '\0';
		while (len-- != 0)
			temp[len] = *(s + start + len);
		return (temp);
	}
	return (NULL);
}
