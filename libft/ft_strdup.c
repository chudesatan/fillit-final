/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:54:19 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 11:54:20 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *strtemp;

	strtemp = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!strtemp)
		return (NULL);
	ft_strcpy(strtemp, s1);
	return (strtemp);
}
