#include "../push_swap.h"

void	add_back(t_node **stack, int data)
{
	t_node	*current;
	t_node	*next;

	if (*stack )
	current->value = data;
}

t_node	*init_stack(int argc, char **argv)
{
	int		i;
	char	**tmp;
	t_node	*stack_a;
	
	stack_a = NULL:
	if (argc == 2)
		tmp = ft_split(argv[i], ' ');
	else 
	{
		i = 1;
		tmp = argv;
	}
	while (tmp[i])
	{
		add_back(&stack_a, ft_atoi(tmp[i]));
		i++;
	}
	if (argc == 2)
		ft_free(tmp);
	return(stack_a);
}