#include "push_swap.h"

int free_stack(t_node **node)
{
	t_node	*tmp;
	t_node	*current;

	if (!node || !*node)
		return (0);
	current = *node;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*node = NULL;
	return (0);
}

int	check_duplicates(t_node *stack_a)
{
	t_node	*current;
	t_node	*runner;

	if (!stack_a)
		return (0);
	current = stack_a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);	
}

void	free_all(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->push_cost = 0;
	node->cheapest = 0;
	node->next = NULL;
	return (node);
}

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*tail;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = *lst;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
}

t_node	*last_node(t_node *lst)
{
	t_node	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
int	find_size(t_node *lst)
{
	int		count;
	t_node	*temp;

	if (!lst)
		return (0);
	count = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
