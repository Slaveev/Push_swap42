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

// int	ft_stack_len(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	if (stack == NULL)
// 		return (0);
// 	while (stack)
// 	{
// 		i++;
// 		stack = stack->next;
// 	}
// 	return (i);
// }
