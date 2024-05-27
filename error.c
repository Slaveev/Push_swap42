/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:11:14 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:17:52 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

// TODO //
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int	arguments_error(char **argv)
{
	int		i;
	long	n;
	t_stack	*tmp;

	tmp = NULL;
	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		if (is_all_digit(argv[i]) != 0)
		{
			write(1, "here is the error\n", 18);
			return (1);
		}
		append_node(&tmp, n);
		if (error_duplicate(tmp, n) != 0)
		{
			free_stack(&tmp);
			return (1);
		}
		i++;
	}
	write(1, "the f\n", 6);
	free_stack(&tmp);
	return (0);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
