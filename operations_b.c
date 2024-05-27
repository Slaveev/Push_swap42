/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:59:28 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:04:47 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sb (swap b) : swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements).
void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

// pb (push b) : take the first element at the top of b and
// put it at the top of b. Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a == NULL || (*a) == NULL)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	write(1, "pb\n", 3);
}

// rb (rotate b) : shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	last = find_last(*b);
	*b = last;
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

// rrb (reverse rotate b) : shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *b;
	*b = tmp;
	if (prev)
		prev->next = NULL;
	write(1, "rrb\n", 4);
}
