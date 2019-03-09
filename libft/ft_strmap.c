/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:05:15 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/14 16:05:16 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s != NULL && f != NULL)
	{
		i = 0;
		len = ft_strlen(s);
		str = ft_strnew(len);
		if (str == NULL)
			return (NULL);
		while (i < len)
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
