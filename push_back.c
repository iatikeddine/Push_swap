/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:48:14 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/20 11:49:03 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_value(t_stack *b, int value)
{
	while (b->array[b->top] != value)
	{
		if (rb_tochunk(b, value) <= rrb_tochunk(b, value))
			rb(b);
		else
			rrb(b);
	}
}

static int	calculate_min_cost(t_stack *b, int value)
{
	int	cost_rb;
	int	cost_rrb;

	cost_rb = rb_tochunk(b, value);
	cost_rrb = rrb_tochunk(b, value);
	if (cost_rb < cost_rrb)
		return (cost_rb);
	return (cost_rrb);
}

static void	push_max_value(t_stack *a, t_stack *b, int *tmp, int *target)
{
	rotate_b_to_value(b, tmp[*target]);
	pa(a, b);
	(*target)--;
}

static void	push_two_values(t_stack *a, t_stack *b, int *tmp, int *target)
{
	rotate_b_to_value(b, tmp[*target - 1]);
	pa(a, b);
	rotate_b_to_value(b, tmp[*target]);
	pa(a, b);
	if (a->top > 0 && a->array[a->top] > a->array[a->top - 1])
		sa(a);
	(*target) -= 2;
}

void	push_back(t_stack *a, t_stack *b, int *tmp)
{
	int	target;
	int	cost_max;
	int	cost_second;

	target = b->top;
	while (b->top >= 0)
	{
		if (target == 0)
		{
			pa(a, b);
			return ;
		}
		cost_max = calculate_min_cost(b, tmp[target]);
		cost_second = calculate_min_cost(b, tmp[target - 1]);
		if (cost_max <= cost_second)
			push_max_value(a, b, tmp, &target);
		else
			push_two_values(a, b, tmp, &target);
	}
}
