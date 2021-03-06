/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:20:15 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 13:20:16 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char symb;

	if (c <= 255 && c >= 0)
	{
		symb = (unsigned char)c;
		if (symb >= 32 && symb <= 126)
			return (1);
	}
	return (0);
}
