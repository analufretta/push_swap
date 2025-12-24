/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:49:07 by afretta-          #+#    #+#             */
/*   Updated: 2025/10/21 15:05:09 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_allocation(char **arr, size_t index, size_t len)
{
	size_t	i;

	arr[index] = malloc(sizeof(char) * (len + 1));
	if (!arr[index])
	{
		i = 0;
		while (i < index)
			free(arr[i++]);
		free(arr);
		return (1);
	}
	return (0);
}

static int	fill_array(char **arr, char const *str, char delimiter)
{
	size_t	len;
	size_t	index;

	index = 0;
	while (*str)
	{
		len = 0;
		while ((*str) && (*str == delimiter))
			str++;
		while ((*str) && (*str != delimiter))
		{
			len++;
			str++;
		}
		if (len)
		{
			if (safe_allocation(arr, index, len))
				return (1);
			ft_strlcpy(arr[index], str - len, len + 1);
			index++;
		}
	}
	arr[index] = NULL;
	return (0);
}

static size_t	count_words(char const *s, char separator)
{
	size_t	count;
	int		inword;

	count = 0;
	while (*s)
	{
		inword = 0;
		while ((*s == separator) && *s)
			s++;
		while ((*s != separator) && *s)
		{
			if (inword == 0)
			{
				count++;
				inword = 1;
			}
			s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	char	**arr;

	wordcount = count_words(s, c);
	arr = malloc(sizeof(char *) * (wordcount + 1));
	if (!arr)
		return (NULL);
	if (fill_array(arr, s, c))
		return (NULL);
	return (arr);
}
