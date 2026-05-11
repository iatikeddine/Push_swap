/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:32:27 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/18 10:02:04 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*array;
	int	top;
}	t_stack;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *s, int *err);
int		is_sorted(t_stack *a);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		*sorted_array(t_stack *a);
int		in_range(int number, int start, int end);
int		stack_duplicate(t_stack *a);
int		check_validity(char **array);
int		num_count(int argc, char **argv);
int		rb_tochunk(t_stack *b, int number);
int		rrb_tochunk(t_stack *b, int number);
int		fill_stack(t_stack *a, int argc, char **argv);
void	free_array(char **array);
void	push_swap(t_stack *a, t_stack *b);
void	push_chunks(t_stack *a, t_stack *b, int *tmp, int chunk);
void	push_back(t_stack *a, t_stack *b, int *tmp);
void	swap(int *a, int *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
