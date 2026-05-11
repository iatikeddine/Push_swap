/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:34 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/22 09:54:44 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static void	apply_operations(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(op, "sa"))
		sa(a);
	else if (!ft_strcmp(op, "sb"))
		sb(b);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b);
	else if (!ft_strcmp(op, "pa"))
		pa(a, b);
	else if (!ft_strcmp(op, "pb"))
		pb(a, b);
	else if (!ft_strcmp(op, "ra"))
		ra(a);
	else if (!ft_strcmp(op, "rb"))
		rb(b);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b);
	else if (!ft_strcmp(op, "rra"))
		rra(a);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b);
	else
		write_error();
}

void	read_and_apply(t_stack *a, t_stack *b)
{
	char	*line;
	size_t	len;

	line = get_next_line(0);
	while (line)
	{
		len = ft_strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (line[0] == '\0')
			write_error();
		apply_operations(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}
