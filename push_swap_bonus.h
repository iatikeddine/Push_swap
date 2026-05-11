/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatikedd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:51:30 by iatikedd          #+#    #+#             */
/*   Updated: 2025/12/22 09:18:16 by iatikedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

typedef struct s_stack
{
	int	*array;
	int	top;
}	t_stack;

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		is_sorted(t_stack *a);
int		ft_atoi(const char *s, int *err);
char	**ft_split(char const *s, char c);
void	free_array(char **array);
int		stack_duplicate(t_stack *a);
int		check_validity(char **array);
int		num_count(int argc, char **argv);
int		fill_stack(t_stack *a, int argc, char **argv);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	write_error(void);
void	ss(t_stack *a, t_stack *b);
void	read_and_apply(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif