/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:28:17 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 13:28:18 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char symb;

	if (c <= 255 && c >= 0)
	{
		symb = (unsigned char)c;
		if (ft_isalpha(symb) || ft_isdigit(symb))
			return (1);
	}
	return (0);
}
