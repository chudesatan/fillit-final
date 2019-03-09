/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:11:10 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/15 17:11:11 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s != NULL && f != NULL)
	{
		i = 0;
		len = ft_strlen(s);
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		while (i < len)
		{
			str[i] = f((unsigned int)i, s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
