#include "push_swap.h"

void    reverse_rotate(t_node **stack)
{
    t_node *penultimate;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
		return ;
    penultimate = *stack;
    while (penultimate->next->next != NULL)
        penultimate = penultimate->next;
    last = penultimate->next;
    penultimate->next = NULL;
    last->next = *stack;
    *stack = last;
}

void    rra(t_node **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_node **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void    rrr(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}