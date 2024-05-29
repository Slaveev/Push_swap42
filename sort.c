/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:21:03 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 15:38:14 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = biggest_node(*stack);
	if (tmp == *stack)
		ra(stack);
	else if (tmp == (*stack)->next)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

void	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*min;

	i = 0;
	while (i < 2)
	{
		min = find_min(*stack_a);
		while (min->nbr != (*stack_a)->nbr)
			ra(stack_a);
		pb(stack_a, stack_b);
		i++;
	}
	three_sort(stack_a);
	i = 0;
	while (i < 2)
	{
		if (*stack_b == NULL)
			break ;
		min = find_min(*stack_b);
		if ((*stack_b)->nbr == min->nbr)
			rb(stack_b);
		pa(stack_a, stack_b);
		// while (min->nbr != (*stack_b)->nbr)
		// 	rb(stack_b);
		// pa(stack_a, stack_b);
	}
}

int get_min_index(t_stack *stack)
{
    t_stack *current = stack;
    int min_value = INT_MAX;
    int min_index = 0;
    int index = 0;

    while (current)
    {
        if (current->nbr < min_value)
        {
            min_value = current->nbr;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return min_index;
}

void move_min_to_top(t_stack **stack)
{
    int min_index = get_min_index(*stack);
    int stack_size = ft_stack_len(*stack);

    if (min_index < stack_size / 2)
    {
        while (min_index--)
            ra(stack);
    }
    else
    {
        min_index = stack_size - min_index;
        while (min_index--)
            rra(stack);
    }
}

void sort_all(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size = ft_stack_len(*stack_a);
    while (stack_size > 3)
    {
        move_min_to_top(stack_a);
        pb(stack_a, stack_b);
        stack_size--;
    }
    three_sort(stack_a);
    while (ft_stack_len(*stack_b) > 0)
    {
        pa(stack_a, stack_b);
    }
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_stack_len(*stack_a);
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		three_sort(stack_a);
	else if (stack_size == 5)
		five_sort(stack_a, stack_b);
	else
		sort_all(stack_a, stack_b);
}
