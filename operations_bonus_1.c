/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:37:00 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/22 08:38:00 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	int	swap;

	if (a->top <= 0)
		return ;
	swap = a->array[a->top];
	a->array[a->top] = a->array[a->top - 1];
	a->array[a->top - 1] = swap;
}

void	sb(t_stack *b)
{
	int	swap;

	if (b->top <= 0)
		return ;
	swap = b->array[b->top];
	b->array[b->top] = b->array[b->top - 1];
	b->array[b->top - 1] = swap;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top < 0)
		return ;
	a->top++;
	a->array[a->top] = b->array[b->top];
	b->top--;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top < 0)
		return ;
	b->top++;
	b->array[b->top] = a->array[a->top];
	a->top--;
}
