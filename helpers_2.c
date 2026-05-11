/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:03:05 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/24 09:23:32 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(int number, int start, int end)
{
	return (number >= start && number <= end);
}

int	rb_tochunk(t_stack *b, int number)
{
	int	i;

	i = b->top;
	while (i >= 0 && b->array[i] != number)
		i--;
	return (b->top - i);
}

int	rrb_tochunk(t_stack *b, int number)
{
	int	i;

	i = 0;
	while (i <= b->top && b->array[i] != number)
		i++;
	return (i + 1);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->array[i] < a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
