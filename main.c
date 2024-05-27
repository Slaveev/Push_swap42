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

int	main(int argc, char **argv)
{
	t_stack	*stack_one;
	t_stack	*stack_two;

	stack_one = NULL;
	stack_two = NULL;
	atexit(leaks);
	if (arguments_checker(argc, argv) != 0)
		return (1);
	init_stack(&stack_one, argv);
	if (if_sorted(stack_one) == 0)
		return (0);
	check_sort(&stack_one, &stack_two);
	free_stack(&stack_one);
	if (argc == 2)
		free_array(argv);
	return (0);
}
