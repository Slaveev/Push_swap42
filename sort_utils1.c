#include "push_swap.h"

int find_min_nbr(t_stack *stack)
{
    int min;
    t_stack *current;

    current = stack->next;
    min = stack->nbr;
    while (current)
    {
        if (current->nbr < min)
            min = current->nbr;
        current = current->next;
    }
    return (min);
}

int find_max_nbr(t_stack *stack)
{
    int max;
    t_stack *current;

    current = stack->next;
    max = stack->nbr;
    while (current)
    {
        if (current->nbr > max)
            max = current->nbr;
        current = current->next;
    }
    return (max);
}

bool number_in_range(t_stack *stack, int min, int max)
{
    t_stack *current;

    current = stack;
    while (current)
    {
        if (current->nbr >= min && current->nbr <= max)
            return (true);
        current = current->next;
    }
    return (false);
}

int find_index_in_range(t_stack *stack, int min, int max)
{
    int index;
    t_stack *current;

    index = 0;
    current = stack;
    while (current)
    {
        if (current->nbr >= min && current->nbr <= max)
            return (index);
        index++;
        current = current->next;
    }
    return (-1);
}

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}