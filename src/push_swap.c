#include "push_swap.h"

int is_sorted(t_node *stack_a)
{
    if (!stack_a)
        return (1);
    while (stack_a->next != NULL)
    {
        if (stack_a->value > stack_a->next->value)
            return (0);
        stack_a = stack_a->next;
    }
    return (1);
}

t_node  *find_min(t_node *stack)
{
    t_node *min_node;

    if (!stack)
        return (NULL);
    min_node = stack;
    while (stack)
    {
        if (min_node->value > stack->value)
            min_node = stack;
        stack = stack->next;
    }
    return (min_node);
}

t_node  *find_max(t_node *stack)
{
    t_node *max_node;

    if (!stack)
        return (NULL);
    max_node = stack;
    while (stack)
    {
        if (max_node->value < stack->value)
            max_node = stack;
        stack = stack->next;
    }
    return (max_node);
}

void  sort_three(t_node **stack_a)
{
    t_node	*highest_node;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
    highest_node = find_max(*stack_a);
    if (*stack_a == highest_node)
        ra(stack_a);
    else if ((*stack_a)->next == highest_node)
        rra(stack_a);
    if((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void    set_current_position(t_node *stack)
{
    int i;
    int median;

    i = 0;
    median = find_size(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = 1;
        else 
            stack->above_median = 0;
        stack = stack->next;
        i++;
    }    
}

void    set_target_a(t_node *stack_a, t_node *stack_b)
{
    t_node  *current_b;
    t_node  *target_node;
    long    best_match_value;

    while (stack_a)
    {
        best_match_value = LONG_MIN;
        current_b = stack_b;
        while (current_b)
        {
            if (current_b->value < stack_a->value && current_b->value > best_match_value)
            {
                best_match_value = current_b->value;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_value == LONG_MIN)
            stack_a->target_node = find_max(stack_b);
        else
            stack_a->target_node = target_node;
        stack_a = stack_a->next;
    }
}

void    calculate_cost(t_node *stack_a, t_node *stack_b)
{
    int len_a;
    int len_b;

    len_a = find_size(stack_a);
    len_b = find_size(stack_b);
    while (stack_a)
    {
        if (stack_a->above_median)
            stack_a->push_cost = stack_a->index;
        else
            stack_a->push_cost = len_a - (stack_a->index);
        if (stack_a->target_node->above_median)
            stack_a->push_cost += stack_a->target_node->index;
        else
            stack_a->push_cost += len_b - (stack_a->target_node->index);
        stack_a = stack_a->next;
    }
}

void    set_cheapest(t_node *stack)
{
    long cheapest_value;
    t_node *cheapest_node;

    if (!stack)
        return ;
    cheapest_value = LONG_MAX;
    while (stack)
    {
        stack->cheapest = 0;
        if(stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = 1;
}

t_node  *get_cheapest_node(t_node *stack)
{
    if (!stack)
        return (NULL);
    while(stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void	finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

static void move_a_to_b(t_node **stack_a, t_node **stack_b)
{
    t_node *cheapest_node;

    cheapest_node = get_cheapest_node(*stack_a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
    {
        while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
            rr(stack_a, stack_b);
        set_current_position(*stack_a);
        set_current_position(*stack_b);
    }
    else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
    {
        while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
            rrr(stack_a, stack_b);
        set_current_position(*stack_a);
        set_current_position(*stack_b);
    }
    finish_rotation(stack_a, cheapest_node, 'a');
	finish_rotation(stack_b, cheapest_node->target_node, 'b');
	pb(stack_a, stack_b);
}

void    set_target_b(t_node *stack_a, t_node *stack_b)
{
    t_node  *current_a;
    t_node  *target_node;
    long    best_match_value;

    while (stack_b)
    {
        best_match_value = LONG_MAX;
        current_a = stack_a;
        while (current_a)
        {
            if (current_a->value > stack_b->value && current_a->value < best_match_value)
            {
                best_match_value = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_value == LONG_MAX)
            stack_b->target_node = find_min(stack_a);
        else
            stack_b->target_node = target_node;
        stack_b = stack_b->next;
    }
}

void    min_on_top(t_node **stack)
{
    t_node *min_node;

    min_node = find_min(*stack);
    if (min_node->above_median)
    {
        while (*stack != min_node)
            ra(stack);
    }
    else
    {
        while (*stack != min_node)
            rra(stack);
    }
}

static void set_info_a(t_node *stack_a, t_node *stack_b)
{
    set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_a(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}

static void	set_info_b(t_node *stack_a, t_node *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_b(stack_a, stack_b);
}

void push_swap(t_node **stack_a, t_node **stack_b)
{
    int len_a;

    len_a = find_size(*stack_a);
    if (len_a == 2)
        sa(stack_a);
    else if (len_a == 3)
        sort_three(stack_a);
    else
    {
        pb(stack_a, stack_b);
        if (len_a > 4)
            pb(stack_a, stack_b);
        while (find_size(*stack_a) > 3)
        {
            set_info_a(*stack_a, *stack_b);
            move_a_to_b(stack_a, stack_b);
        }
        sort_three(stack_a);
        while (*stack_b)
        {
            set_info_b(*stack_a, *stack_b);
            finish_rotation(stack_a, (*stack_b)->target_node, 'a');
            pa(stack_a, stack_b);
        }
        set_current_position(*stack_a);
        min_on_top(stack_a);
    }
}
