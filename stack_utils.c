/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:20:32 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 15:20:54 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*cur;

	if (stack == NULL)
		return (NULL);
	min_node = stack;
	cur = stack->next;
	while (cur != NULL)
	{
		if (cur->nbr < min_node->nbr)
			min_node = cur;
		cur = cur->next;
	}
	return (min_node);
}

t_stack	*biggest_node(t_stack *stack)
{
	t_stack	*big_node;
	t_stack	*cur;

	if (stack == NULL)
		return (NULL);
	big_node = stack;
	cur = stack->next;
	while (cur != NULL)
	{
		if (cur->nbr > big_node->nbr)
			big_node = cur;
		cur = cur->next;
	}
	return (big_node);
}

int ft_stack_len(t_stack *stack)
{
    int len;
	
	len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
}

int find_correct_position(t_stack *b, int nbr)
{
    int position;
    t_stack *current;
	
	current = b;
	position = 0;
    while (current && current->nbr > nbr)
    {
        position++;
        current = current->next;
    }
    return (position);
}

int ft_find_index(t_stack *a, int nbr)
{
    int index;
	t_stack *current;

	index = 0;
    current = a;
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
