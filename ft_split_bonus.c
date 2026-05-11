/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:21:52 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/06 10:02:23 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

void	free_all(char **array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	strings_alloc(char **array, char const *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				i++;
				j++;
			}
			array[index] = malloc(j + 1);
			if (!array[index])
				return (free_all(array, index), 0);
			index++;
		}
	}
	return (array[index] = NULL, 1);
}

void	split_fill(char **array, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			while (s[i] && s[i] != c)
			{
				array[j][k] = s[i];
				i++;
				k++;
			}
			array[j][k] = 0;
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	if (!strings_alloc(array, s, c))
		return (NULL);
	split_fill(array, s, c);
	return (array);
}
