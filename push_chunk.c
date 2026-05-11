/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:02:00 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/18 11:02:05 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_chunk
{
	int	start;
	int	end;
	int	pushed;
	int	len;
	int	size;
}	t_chunk;

static void	clamp_end(t_chunk *c)
{
	if (c->end >= c->len)
		c->end = c->len - 1;
}

static void	push_in_chunk(t_stack *a, t_stack *b, int *tmp, t_chunk *c)
{
	int	mid;

	mid = tmp[c->start + (c->end - c->start) / 2];
	pb(a, b);
	if (b->array[b->top] <= mid)
		rb(b);
	c->pushed++;
	if (c->pushed == c->size)
	{
		c->start += c->size;
		c->end += c->size;
		c->pushed = 0;
	}
}

void	push_chunks(t_stack *a, t_stack *b, int *tmp, int chunk)
{
	t_chunk	c;

	c.len = a->top + 1;
	c.size = chunk;
	c.start = 0;
	c.end = chunk - 1;
	c.pushed = 0;
	while (a->top >= 0)
	{
		clamp_end(&c);
		if (in_range(a->array[a->top], tmp[c.start], tmp[c.end]))
			push_in_chunk(a, b, tmp, &c);
		else
			ra(a);
	}
}
