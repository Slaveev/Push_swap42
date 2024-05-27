/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:40:42 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:00:37 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements).
void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

// pa (push a) : take the first element at the top of b and
// put it at the top of a. Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (b == NULL || (*b) == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	write(1, "pa\n", 3);
}

// ra (rotate a) : shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	last = find_last(*a);
	*a = last;
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *a;
	*a = tmp;
	if (prev)
		prev->next = NULL;
	write(1, "rra\n", 4);
}

