/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:38:15 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/22 08:39:01 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	int	top;
	int	i;

	if (a->top <= 0)
		return ;
	i = a->top;
	top = a->array[a->top];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = top;
}

void	rb(t_stack *b)
{
	int	top;
	int	i;

	if (b->top <= 0)
		return ;
	i = b->top;
	top = b->array[b->top];
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = top;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	int	bottom;
	int	i;

	if (a->top <= 0)
		return ;
	bottom = a->array[0];
	i = 0;
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->top] = bottom;
}

void	rrb(t_stack *b)
{
	int	bottom;
	int	i;

	if (b->top <= 0)
		return ;
	bottom = b->array[0];
	i = 0;
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->top] = bottom;
}
