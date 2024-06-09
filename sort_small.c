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
