/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozkara <nozkara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:57:26 by nozkara           #+#    #+#             */
/*   Updated: 2023/12/28 19:30:01 by nozkara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_w(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

void	*ft_free(char **words, int k)
{
	k -= 1;
	while (k >= 0)
	{
		free(words[k]);
		k--;
	}
	free(words);
	return (NULL);
}

void	part2(char *s, int *i, int *start, char c)
{
	while (s[*i] == c)
		(*i)++;
	*start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		k;
	char	**words;

	i = count_w(s, c);
	words = (char **) malloc(sizeof(char *) * (i + 1));
	if (!words)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		part2((char *)s, &i, &start, c);
		if (i > start)
		{
			words[k] = ft_substr(s, start, (i - start));
			if (words[k] == NULL)
				return (ft_free(words, k));
			k++;
		}
	}
	words[k] = NULL;
	return (words);
}
