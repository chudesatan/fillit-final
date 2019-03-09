/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:52:38 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/16 14:52:40 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;

	if (s1 != NULL && s2 != NULL)
	{
		t = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (t == NULL)
			return (NULL);
		ft_strcpy(t, s1);
		ft_strcat(t, s2);
		return (t);
	}
	return (NULL);
}
