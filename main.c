/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:28:59 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:14:13 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}

void print_stack(const char *name, t_stack *stack)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
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

    // atexit(leaks);
int main(int argc, char **argv)
{
    t_stack *stack_one;
    t_stack *stack_two;
    char **args;

    stack_one = NULL;
    stack_two = NULL;
    args = arguments_checker(argc, argv);
    if (!args)
	{
        return (1);
	}
    init_stack(&stack_one, args);
    if (if_sorted(stack_one) == 0)
        return (0);
    check_sort(&stack_one, &stack_two);
    // free_stack(&stack_one);
    if (argc == 2)
        free_array(args);
    return (0);
}

