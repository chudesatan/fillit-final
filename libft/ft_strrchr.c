/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:35:33 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 11:35:35 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	long	len;

	len = ft_strlen(s);
	str = (char *)s;
	while (len != -1)
	{
		if (*(str + len) == (char)c)
			return (str + len);
		len--;
	}
	return (NULL);
}
