/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:47:17 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/23 17:47:18 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	unsigned char symb;

	if (c <= 255 && c >= 0)
	{
		symb = (unsigned char)c;
		if (symb >= 'a' && symb <= 'z')
			return ((int)symb + 'A' - 'a');
	}
	return (c);
}
