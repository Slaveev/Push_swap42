/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:14:12 by dslaveev          #+#    #+#             */
/*   Updated: 2024/05/27 16:19:04 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_duplicate(t_stack *stack, int n)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->nbr == n)
        {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int is_all_digit(char *argv)
{
    int i = 0;

    if (argv[i] == '\0')
        return (1);
    while (argv[i])
    {
        if (argv[i] < '0' || argv[i] > '9')
        {
            return (1);
        }
        i++;
    }
    return (0);
}


int	syntax_error(char *str)
{
	int	i;
	int	repetitive;

	i = 0;
	repetitive = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		repetitive += 1;
		i++;
	}
	if (repetitive > 1)
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
