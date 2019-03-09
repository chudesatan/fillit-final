/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:32:47 by fhagrave          #+#    #+#             */
/*   Updated: 2019/01/24 13:32:48 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_vars(long *result, int *is_negative, int *index)
{
	*result = 0;
	*index = 0;
	*is_negative = 0;
}

static char	*remove_spaces(char *str)
{
	while (str[0] == ' ' || str[0] == '\t' || str[0] == '\n'
		|| str[0] == '\f' || str[0] == '\v' || str[0] == '\r')
		str++;
	return (str);
}

static char	*remove_signs_then_zeroes(char *str, int *is_negative)
{
	if (str[0] == '-' && str++)
		*is_negative = 1;
	else if (str[0] == '+')
		str++;
	while (str[0] == '0')
		str++;
	return (str);
}

static int	digit_number(long result)
{
	if (result > 0)
		return (digit_number(result / 10) + 1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		is_negative;
	int		index;
	long	result;
	char	*st;

	st = (char *)str;
	init_vars(&result, &is_negative, &index);
	st = remove_spaces(st);
	if (st[0] == '\e')
		return (0);
	st = remove_signs_then_zeroes(st, &is_negative);
	while (st[index] >= '0' && st[index] <= '9' && ++index)
	{
		result *= 10;
		result += st[index - 1] - '0';
		if (digit_number(result) == digit_number(10 * result))
			return (is_negative ? 0 : -1);
	}
	if (is_negative)
		result *= -1;
	return ((int)result);
}
