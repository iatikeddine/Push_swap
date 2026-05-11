/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:53:42 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/22 08:56:00 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_duplicate(t_stack *a)
{
	int	i;
	int	k;

	i = 0;
	while (i <= a->top)
	{
		k = i + 1;
		while (k <= a->top)
		{
			if (a->array[i] == a->array[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	check_validity(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if ((array[i][j] == '+' || array[i][j] == '-'))
			{
				if (j != 0)
					return (0);
				if (!ft_isdigit(array[i][j + 1]))
					return (0);
			}
			if (!ft_isdigit(array[i][j]) &&
				array[i][j] != '+' && array[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	num_count(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**array;

	count = 0;
	i = 1;
	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		if (!check_validity(array))
		{
			free_array(array);
			return (-1);
		}
		j = 0;
		while (array[j])
		{
			j++;
			count++;
		}
		free_array(array);
		i++;
	}
	return (count);
}

int	fill_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**array;
	int		err;

	i = 1;
	k = a->top;
	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		j = 0;
		while (array[j])
		{
			a->array[k] = ft_atoi(array[j], &err);
			if (err)
				return (free_array(array), 0);
			j++;
			k--;
		}
		free_array(array);
		i++;
	}
	return (1);
}
