/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:18:54 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:13:29 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_stack **stack_one, t_stack **stack_two)
{
	if (if_sorted(*stack_one) == 0)
		return ;
	if (if_sorted(*stack_one) != 0)
		sort(stack_one, stack_two);
}

int	if_sorted(t_stack *stack_one)
{
	t_stack	*tmp;

	tmp = stack_one;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_median(t_stack *stack, int size)
{
	int *values = malloc(sizeof(int) * size);
	t_stack *current = stack;
	int i = 0;

	while (current)
	{
		values[i++] = current->nbr;
		current = current->next;
	}
	qsort(values, size, sizeof(int), compare_int);
	int median = values[size / 2];
	free(values);
	return (median);
}

int compare_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

// void partition(t_stack **a, t_stack **b, int median)
// {
// 	int size = ft_stack_len(*a);
// 	int pushes = 0;
// 	int i = 0;

// 	while (i < size)
// 	{
// 		if ((*a)->nbr <= median)
// 		{
// 			pb(a, b);
// 			pushes++;
// 		}
// 		else
// 		{
// 			ra(a);
// 		}
// 		i++;
// 	}
// }
