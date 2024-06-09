// void sort_all(t_stack **stack_a, t_stack **stack_b)
// {
//     int min = find_min_nbr(*stack_a);
//     int max = find_max_nbr(*stack_a);
//     int size = ft_stack_len(*stack_a);
//     int chunk_size = ceil((max - min + 1) / sqrt(size));
//     int i = max;

//     while (i >= min)
//     {
//         int chunk_start = (i - chunk_size > min) ? i - chunk_size : min;
//         while (number_in_range(*stack_a, chunk_start, i))
//         {
//             int index = find_index_in_range(*stack_a, chunk_start, i);
//             int len = ft_stack_len(*stack_a);

//             if (index <= len / 2)
//             {
//                 while (index-- > 0)
//                     ra(stack_a);
//             }
//             else
//             {
//                 index = len - index;
//                 while (index-- > 0)
//                     rra(stack_a);
//             }
//             pb(stack_a, stack_b);
//         }
//         i -= chunk_size;
//     }
//     sort_stack_b_descending(stack_a, stack_b);
// }

t_stack *find_max(t_stack *stack)
{
    t_stack *max_node;
    t_stack *cur;

    if (stack == NULL)
        return (NULL);
    max_node = stack;
    cur = stack->next;
    while (cur != NULL)
    {
        if (cur->nbr > max_node->nbr)
            max_node = cur;
        cur = cur->next;
    }
    return (max_node);
}

int find_smallest(t_stack *stack)
{
    int smallest = stack->nbr;
    t_stack *current = stack->next;

    while (current)
    {
        if (current->nbr < smallest)
            smallest = current->nbr;
        current = current->next;
    }
    return (smallest);
}

void push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        pa(stack_a, stack_b);
    }
}

// void sort_stack_b_descending(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *max_node;

//     while (*stack_b)
//     {
//         max_node = find_max(*stack_b);
//         while ((*stack_b)->nbr != max_node->nbr)
//         {
//             rb(stack_b); // Rotate stack_b to bring max to the top
//         }
//         pa(stack_a, stack_b); // Push max from stack_b to stack_a
//     }
// }

void sort_three_elements(t_stack **stack_a)
{
    three_sort(stack_a);
}

void push_to_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
    while (ft_stack_len(*stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
}

int is_descending(t_stack *stack) {
    while (stack && stack->next) {
        if (stack->nbr < stack->next->nbr)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void move_min_to_top(t_stack **stack)
{
    int min_index = get_min_index(*stack);
    int stack_size = ft_stack_len(*stack);

    if (min_index < stack_size / 2)
    {
        while (min_index--)
            ra(stack);
    }
    else
    {
        min_index = stack_size - min_index;
        while (min_index--)
            rra(stack);
    }
}

void sort_stack_b_descending(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        int max = find_max_nbr(*stack_b);
        int index = ft_find_index(*stack_b, max);
        int len = ft_stack_len(*stack_b);

        if (index <= len / 2)
        {
            while (index-- > 0)
                rb(stack_b);
        }
        else
        {
            index = len - index;
            while (index-- > 0)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}
