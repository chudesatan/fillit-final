/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:31:38 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/14 14:31:39 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *temp;

	if (size + 1 == 0)
		return (NULL);
	temp = (char*)malloc(sizeof(*temp) * (size + 1));
	if (!temp)
		return (NULL);
	while (size-- != 0)
		temp[size + 1] = '\0';
	temp[0] = '\0';
	return (temp);
}
