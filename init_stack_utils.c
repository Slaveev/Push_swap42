/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:19:39 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:15:45 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->nbr = n;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		tmp = find_last(*stack);
		tmp->next = new;
		new->prev = tmp;
	}
}

void print_stack_a(t_stack *stack)
{
    printf("Stack: ");
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}


// init_stack TODO //
void init_stack(t_stack **stack, char **argv) {
    int i;
    long n;

    i = 0;
    while (argv[i])
	{
        if (syntax_error(argv[i]) != 0)
            ft_error(stack);
        n = ft_atol(argv[i]);
        if (error_duplicate(*stack, n) != 0)
            ft_error(stack);
        append_node(stack, n);
        i++;
    }
}


char **arguments_checker(int argc, char **argv)
{
    char **new_arg;

    if (argc == 1)
	{
        write(2, "Wrong arguments\n", 16);
        return (NULL);
    }
	else if (argc == 2)
	{
        new_arg = ft_split(argv[1], ' ');
        return (new_arg);
    }
	else
	{
        new_arg = argv + 1;
        return (new_arg);
    }
}

// char **arguments_checker(int argc, char **argv)
// {
//     char **new_argv;

//     if (argc == 1)
//     {
//         write(2, "wrong arguments\n", 16);
//         return (NULL);
//     }
//     else if (argc == 2)
//     {
//         new_argv = ft_split(argv[1], ' ');
//         return (new_argv);
//     }
//     else
//     {
//         new_argv = 
//     }
// }

