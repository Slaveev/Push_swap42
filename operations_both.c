/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:59:47 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:00:38 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ss : sa and sb at the same time.
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_a == NULL || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	write(1, "ss\n", 3);
}
