/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhagrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:09:44 by fhagrave          #+#    #+#             */
/*   Updated: 2018/12/16 16:09:45 by fhagrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**fill_array(char const *s, char c, size_t word, char **temp)
{
	size_t	i;
	size_t	len;
	size_t	start;
	size_t	m;

	i = 0;
	m = 0;
	while (m < word && ++m)
	{
		len = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0' && ++i)
			len++;
		if ((temp[m - 1] = ft_strsub(s, (unsigned int)start, len)) == NULL)
		{
			while (m-- != 0)
				free(temp[m]);
			return (NULL);
		}
	}
	return (temp);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;
	int		word_flag;

	i = 0;
	word = 0;
	word_flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && word_flag == 0 && s[i + 1] != '\0')
		{
			word_flag = 1;
			word++;
		}
		if (s[i] != c && s[i + 1] == c && word_flag == 0)
			word++;
		if (s[i] != c && s[i + 1] == c && word_flag == 1)
			word_flag = 0;
		i++;
	}
	if (s[i - 1] != c && word == 0)
		word++;
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	word;
	char	**temp;

	if (s == NULL)
		return (NULL);
	word = count_words(s, c);
	if (word > 0 && ft_strcmp(s, ""))
	{
		temp = (char**)malloc(sizeof(temp) * (word + 1));
		if (!temp)
			return (NULL);
		temp[word] = NULL;
		if ((temp = fill_array(s, c, word, temp)) == NULL)
			return (NULL);
	}
	else
	{
		temp = (char**)malloc(sizeof(temp) * (1));
		if (!temp)
			return (NULL);
		temp[0] = NULL;
	}
	return (temp);
}
