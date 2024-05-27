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
