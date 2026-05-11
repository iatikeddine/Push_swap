/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:30:02 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/14 09:33:04 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	swap;

	if (a->top <= 0)
		return ;
	swap = a->array[a->top];
	a->array[a->top] = a->array[a->top - 1];
	a->array[a->top - 1] = swap;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	swap;

	if (b->top <= 0)
		return ;
	swap = b->array[b->top];
	b->array[b->top] = b->array[b->top - 1];
	b->array[b->top - 1] = swap;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top < 0)
		return ;
	a->top++;
	a->array[a->top] = b->array[b->top];
	b->top--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top < 0)
		return ;
	b->top++;
	b->array[b->top] = a->array[a->top];
	a->top--;
	write(1, "pb\n", 3);
}
