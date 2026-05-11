/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:50:48 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/22 09:54:41 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->array);
	free(b->array);
}

int	allocate_stacks(t_stack *a, t_stack *b, int count)
{
	a->array = malloc(sizeof(int) * count);
	if (!a->array)
		return (0);
	b->array = malloc(sizeof(int) * count);
	if (!b->array)
	{
		free(a->array);
		return (0);
	}
	a->top = count - 1;
	b->top = -1;
	return (1);
}

static int	check_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		count;

	if (argc < 2)
		return (0);
	count = num_count(argc, argv);
	if (count == -1 || !check_empty(argc, argv))
		write_error();
	if (!allocate_stacks(&a, &b, count))
		return (1);
	if (!fill_stack(&a, argc, argv) || !stack_duplicate(&a))
	{
		free_stacks(&a, &b);
		write_error();
	}
	read_and_apply(&a, &b);
	if (is_sorted(&a) && b.top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&a, &b);
	return (0);
}
