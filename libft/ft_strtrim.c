/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:07:53 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/16 15:07:53 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_begin(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return (i);
}

static unsigned int	count_end(char *str, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n')
	{
		len--;
		i++;
	}
	return (i);
}

static char			*empty_srt(void)
{
	char *temp;

	temp = (char*)malloc(sizeof(*temp));
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	return (temp);
}

char				*ft_strtrim(char const *s)
{
	char	*t;
	size_t	start;
	size_t	end;
	size_t	len;

	if (s != NULL)
	{
		t = (char*)s;
		len = ft_strlen(t);
		if (len == 0)
			return (empty_srt());
		start = count_begin(t);
		if (start == len)
			return (empty_srt());
		end = count_end(t, len - 1);
		return (ft_strsub(s, start, len - end - start));
	}
	return (NULL);
}
