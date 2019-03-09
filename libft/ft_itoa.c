/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:51:17 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/16 18:51:18 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_int(int n)
{
	char	*temp;
	size_t	nbr;
	size_t	i;

	if (n == -2147483648)
	{
		if ((temp = (char*)malloc(sizeof(*temp) * 12)) == NULL)
			return (NULL);
		temp[0] = '-';
		i = 9;
		nbr = 214748364;
		while (i-- != 0)
		{
			temp[i + 1] = nbr % 10 + '0';
			nbr /= 10;
		}
		temp[10] = '8';
		temp[11] = '\0';
		return (temp);
	}
	if ((temp = (char*)malloc(sizeof(*temp) * 2)) == NULL)
		return (NULL);
	temp[0] = '0';
	temp[1] = '\0';
	return (temp);
}

char		*ft_itoa(int n)
{
	size_t	nbr;
	size_t	i;
	char	*temp;
	char	isnegative;

	if (n == -2147483648 || n == 0)
		return (min_int(n));
	isnegative = (n > 0) ? 0 : 1;
	i = 0;
	n *= (isnegative && ++i) ? -1 : 1;
	nbr = (size_t)n;
	while (nbr > 0 && ++i)
		nbr /= 10;
	if ((temp = (char*)malloc(sizeof(*temp) * (int)(i + 1))) == NULL)
		return (NULL);
	temp[i] = '\0';
	nbr = (size_t)n;
	while (i-- != 0)
	{
		temp[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (isnegative)
		temp[0] = '-';
	return (temp);
}
