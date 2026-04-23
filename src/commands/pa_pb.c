#include "push_swap.h"

void    push(t_node **dest, t_node **src)
{
    t_node  *node_to_move;

    if (!src|| !*src)
		return ;
    node_to_move = *src;
    *src = (*src)->next;
    node_to_move->next = *dest;
    *dest = node_to_move;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pb\n", 3);
}