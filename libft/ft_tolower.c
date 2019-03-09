/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:49:43 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/23 17:49:45 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	unsigned char symb;

	if (c <= 255 && c >= 0)
	{
		symb = (unsigned char)c;
		if (symb >= 'A' && symb <= 'Z')
			return ((int)symb + 'a' - 'A');
	}
	return (c);
}
