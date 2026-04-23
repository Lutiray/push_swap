#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;

    if (argc == 1)
        return (0);
    stack_b = NULL;
    stack_a = init_stack(argc, argv);
    if (!stack_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }
    push_swap(&stack_a, &stack_b);
    free_stack(&stack_a);
    return (0);
}
