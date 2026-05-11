/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:17:58 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/24 09:22:12 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_tmp(t_stack *a)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(sizeof(int) * (a->top + 1));
	if (!tmp)
		return (0);
	while (i <= a->top)
	{
		tmp[i] = a->array[i];
		i++;
	}
	return (tmp);
}

int	*sorted_array(t_stack *a)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = fill_tmp(a);
	if (!tmp)
		return (0);
	i = 0;
	while (i <= a->top)
	{
		j = 0;
		while (j < a->top)
		{
			if (tmp[j] > tmp[j + 1])
				swap(&tmp[j], &tmp[j + 1]);
			j++;
		}
		i++;
	}
	return (tmp);
}

void	sort_three(t_stack *a)
{
	int	t;
	int	m;
	int	b;

	t = a->array[a->top];
	m = a->array[a->top - 1];
	b = a->array[a->top - 2];
	if (t > m && m < b && t < b)
		sa(a);
	else if (t > m && m > b)
	{
		sa(a);
		rra(a);
	}
	else if (t > m && m < b && t > b)
		ra(a);
	else if (t < m && m > b && t < b)
	{
		sa(a);
		ra(a);
	}
	else if (t < m && m > b && t > b)
		rra(a);
}

static void	sort_five(t_stack *a, t_stack *b, int *tmp)
{
	while (a->top > 2)
	{
		while (a->array[a->top] != tmp[0])
			ra(a);
		pb(a, b);
		while (a->array[a->top] != tmp[1])
			ra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	*tmp;
	int	len;
	int	chunk;

	len = a->top + 1;
	if (len <= 1)
		return ;
	tmp = sorted_array(a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 5)
		sort_five(a, b, tmp);
	else
	{
		if (len <= 100)
			chunk = 28;
		else
			chunk = 68;
		push_chunks(a, b, tmp, chunk);
		push_back(a, b, tmp);
	}
	free(tmp);
}
