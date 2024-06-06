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

#include <math.h>

int ft_stack_len(t_stack *stack);
t_stack *find_max(t_stack *stack);
int ft_find_index(t_stack *stack, int nbr);

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

int is_descending(t_stack *stack) {
    while (stack && stack->next) {
        if (stack->nbr < stack->next->nbr)
            return 0; // Not descending
        stack = stack->next;
    }
    return 1; // Descending
}

void push_to_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
    while (ft_stack_len(*stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
}

void sort_three_elements(t_stack **stack_a)
{
    three_sort(stack_a);
}

// void sort_stack_b_descending(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *max_node;

//     while (*stack_b)
//     {
//         max_node = find_max(*stack_b);
//         while ((*stack_b)->nbr != max_node->nbr)
//         {
//             rb(stack_b); // Rotate stack_b to bring max to the top
//         }
//         pa(stack_a, stack_b); // Push max from stack_b to stack_a
//     }
// }

void push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        pa(stack_a, stack_b);
    }
}

t_stack *find_max(t_stack *stack)
{
    t_stack *max_node;
    t_stack *cur;

    if (stack == NULL)
        return (NULL);
    max_node = stack;
    cur = stack->next;
    while (cur != NULL)
    {
        if (cur->nbr > max_node->nbr)
            max_node = cur;
        cur = cur->next;
    }
    return (max_node);
}

int find_smallest(t_stack *stack)
{
    int smallest = stack->nbr;
    t_stack *current = stack->next;

    while (current)
    {
        if (current->nbr < smallest)
            smallest = current->nbr;
        current = current->next;
    }
    return (smallest);
}

int find_min_nbr(t_stack *stack)
{
    int min = stack->nbr;
    t_stack *current = stack->next;

    while (current)
    {
        if (current->nbr < min)
            min = current->nbr;
        current = current->next;
    }
    return (min);
}

int find_max_nbr(t_stack *stack)
{
    int max = stack->nbr;
    t_stack *current = stack->next;

    while (current)
    {
        if (current->nbr > max)
            max = current->nbr;
        current = current->next;
    }
    return (max);
}

bool number_in_range(t_stack *stack, int min, int max)
{
    t_stack *current = stack;

    while (current)
    {
        if (current->nbr >= min && current->nbr <= max)
            return (true);
        current = current->next;
    }
    return (false);
}

int find_index_in_range(t_stack *stack, int min, int max)
{
    int index = 0;
    t_stack *current = stack;

    while (current)
    {
        if (current->nbr >= min && current->nbr <= max)
            return (index);
        index++;
        current = current->next;
    }
    return (-1);
}

void sort_stack_b_descending(t_stack **stack_a, t_stack **stack_b);

void sort_all(t_stack **stack_a, t_stack **stack_b)
{
    int min = find_min_nbr(*stack_a);
    int max = find_max_nbr(*stack_a);
    int size = ft_stack_len(*stack_a);
    int chunk_size = ceil((max - min + 1) / sqrt(size));
    int i = max;

    while (i >= min)
    {
        int chunk_start = (i - chunk_size > min) ? i - chunk_size : min;
        while (number_in_range(*stack_a, chunk_start, i))
        {
            int index = find_index_in_range(*stack_a, chunk_start, i);
            int len = ft_stack_len(*stack_a);

            if (index <= len / 2)
            {
                while (index-- > 0)
                    ra(stack_a);
            }
            else
            {
                index = len - index; // Correct the logic here
                while (index-- > 0)
                    rra(stack_a);
            }
            pb(stack_a, stack_b);
        }
        i -= chunk_size;
    }
    sort_stack_b_descending(stack_a, stack_b);
}

void sort_stack_b_descending(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        int max = find_max_nbr(*stack_b);
        int index = ft_find_index(*stack_b, max);
        int len = ft_stack_len(*stack_b);

        if (index <= len / 2)
        {
            while (index-- > 0)
                rb(stack_b);
        }
        else
        {
            index = len - index;
            while (index-- > 0)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int ft_find_index(t_stack *a, int nbr)
{
    int index = 0;
    t_stack *current = a;

    while (current)
    {
        if (current->nbr == nbr)
            break ;
        index++;
        current = current->next;
    }
    if (current == NULL)
        return (-1);
    return (index);
}

int find_correct_position(t_stack *b, int nbr)
{
    int position = 0;
    t_stack *current = b;

    while (current && current->nbr > nbr)
    {
        position++;
        current = current->next;
    }
    return (position);
}

int ft_stack_len(t_stack *stack)
{
    int len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
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
