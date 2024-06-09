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

void push_elements_in_chunks(t_stack **stack_a, t_stack **stack_b, int min, int max, int chunk_size)
{
    int chunk_start = min;
    int chunk_end = min + chunk_size;

    while (chunk_start <= max)
    {
        while (number_in_range(*stack_a, chunk_start, chunk_end))
        {
            int index = find_index_in_range(*stack_a, chunk_start, chunk_end);
            int len = ft_stack_len(*stack_a);

            if (index <= len / 2)
            {
                while (index-- > 0)
                    ra(stack_a);
            }
            else
            {
                index = len - index;
                while (index-- > 0)
                    rra(stack_a);
            }
            pb(stack_a, stack_b);
        }
        chunk_start = chunk_end + 1;
        chunk_end = chunk_start + chunk_size;
    }
}

void sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        int max_value = find_max_nbr(*stack_b);
        int index = ft_find_index(*stack_b, max_value);
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

void final_sort(t_stack **stack_a)
{
    int min_index = get_min_index(*stack_a);
    int len = ft_stack_len(*stack_a);

    if (min_index <= len / 2)
    {
        while (min_index-- > 0)
            ra(stack_a);
    }
    else
    {
        min_index = len - min_index;
        while (min_index-- > 0)
            rra(stack_a);
    }
}

void sort_all(t_stack **stack_a, t_stack **stack_b)
{
    int min = find_min_nbr(*stack_a);
    int max = find_max_nbr(*stack_a);
    int size = ft_stack_len(*stack_a);
    int chunk_size = (max - min + 1) / (int)sqrt(size);

    push_elements_in_chunks(stack_a, stack_b, min, max, chunk_size);
    sort_stack_b(stack_a, stack_b);
    final_sort(stack_a);
}
