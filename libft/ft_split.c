/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateremi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:09:56 by nateremi          #+#    #+#             */
/*   Updated: 2025/11/10 16:09:58 by nateremi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || (str[i - 1]) == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

static void	skip_delimiters(const char *str, size_t *i, char c)
{
	while (str[*i] == c && str[*i])
		(*i)++;
}

static char	**copy_word_to_array(const char *str, char **array, char c)
{
	size_t	i;
	size_t	start;
	size_t	word_index;

	i = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		skip_delimiters(str, &i, c);
		if (str[i] == '\0')
			break ;
		start = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		array[word_index] = malloc(i - start + 1);
		if (!array[word_index])
		{
			free_all(array);
			return (NULL);
		}
		ft_strlcpy(array[word_index], str + start, i - start + 1);
		word_index++;
	}
	array[word_index] = NULL;
	return (array);
}

char	**ft_split(const char *str, char c)
{
	char	**array;
	size_t	count;

	if (!str)
		return (NULL);
	count = word_count(str, c);
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!copy_word_to_array(str, array, c))
		return (NULL);
	return (array);
}
