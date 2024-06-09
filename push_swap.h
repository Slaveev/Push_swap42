/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:48:17 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:09:44 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack;

// errors
void	ft_error(t_stack **stack);
void	free_stack(t_stack **stack);
int		arguments_error(char **argv);
void	free_array(char **array);
int		error_duplicate(t_stack *stack, int n);
int		is_all_digit(char *argv);
int		syntax_error(char *str);
int		error_duplicate(t_stack *stack, int n);
// int		is_all_digit(char *argv);
int		syntax_error(char *str);

// init_utils
void	append_node(t_stack **stack, int n);
void	init_stack(t_stack **stack, char **argv);
char	**arguments_checker(int argc, char **argv);
long	ft_atol(const char *str);
t_stack	*find_last(t_stack *stack);

// sort utils
void	check_sort(t_stack **stack_one, t_stack **stack_two);
int		if_sorted(t_stack *stack_one);

// stack utils
int		ft_stack_len(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*biggest_node(t_stack *stack);

// algo
void partition(t_stack **a, t_stack **b, int median);
void move_min_to_top(t_stack **stack);
int get_min_index(t_stack *stack);
void quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size);

// sort
void	three_sort(t_stack **stack);
void	five_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_all(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);
int compare_int(const void *a, const void *b);
int	find_median(t_stack *stack, int size);
int get_min_index(t_stack *stack);
int ft_find_index(t_stack *a, int nbr);
int min(int a, int b);
int find_correct_position(t_stack *b, int nbr);
bool number_in_range(t_stack *stack, int min, int max);
int find_max_nbr(t_stack *stack);
int find_min_nbr(t_stack *stack);
int find_index_in_range(t_stack *stack, int min, int max);

// operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr_sub(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

char	**ft_split(char const *s, char c);
void print_stack(const char *name, t_stack *stack);

// void		set_target_b(t_stack *a, t_stack *b);
// void		init_nodes_b(t_stack *a, t_stack *b);
// void		current_index(t_stack *stack);
// void		set_target_a(t_stack *a, t_stack *b);
// void		cost_for_a(t_stack *a, t_stack *b);
// void		set_cheapest(t_stack *stack);
// void		init_nodes_a(t_stack *a, t_stack *b);
// void		sort(t_stack **a, t_stack **b);
// void		push(t_stack **dst, t_stack **src);
// void		pa(t_stack **a, t_stack **b);
// void		pb(t_stack **b, t_stack **a);
// void		rev_rotate(t_stack **stack);
// void		rra(t_stack **a);
// void		rrb(t_stack **b);
// void		rrr(t_stack **a, t_stack **b);
// void		rotate(t_stack **stack);
// void		ra(t_stack **a);
// void		rb(t_stack **b);
// void		rr(t_stack **a, t_stack **b);
// void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
// void		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
// void		move_a(t_stack **a, t_stack **b);
// void		move_b(t_stack **a, t_stack **b);
// void		min_on_top(t_stack **a);
// void		sort_stacks(t_stack **a, t_stack **b);
// void		swap(t_stack **head);
// void		sa(t_stack **a);
// void		sb(t_stack **b);
// void		ss(t_stack **a, t_stack **b);
// void		sort_three(t_stack **a);
// int			stack_len(t_stack *stack);
// t_stack		*find_last(t_stack *stack);
// bool		stack_sorted(t_stack *stack);
// t_stack		*find_min(t_stack *stack);
// t_stack		*find_max(t_stack *stack);
// void		append_node(t_stack **stack, int n);
// void		init_stack_a(t_stack **a, char **argv);
// t_stack		*get_cheapest(t_stack *stack);
// void		complete_push(t_stack **stack, t_stack *node, char c);
// int			error_syntax(char *str);
// int			error_duplicate(t_stack *stack, int n);
// void		free_errors(t_stack **a);
// void		free_stack(t_stack **a);
// void		free_array(char **array);
// long		ft_atol(const char *str);

#endif
