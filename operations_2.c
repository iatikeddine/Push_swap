/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:34:00 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/17 12:34:06 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}
