/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:27:32 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 13:27:33 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char symb;

	if (c <= 255 && c >= 0)
	{
		symb = (unsigned char)c;
		if ((symb >= 'A' && symb <= 'Z') || (symb >= 'a' && symb <= 'z'))
			return (1);
	}
	return (0);
}
