#include "push_swap.h"

static int	skip_space_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'
			|| str[*i] == '\n' || str[*i] == '\r'
			|| str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	return (sign);
}

int	safe_atoi(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	i = 0;
	sign = skip_space_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i++] - '0');
		if (sign == 1 && num > INT_MAX)
			return (0);
		if (sign == -1 && -num < INT_MIN)
			return (0);
	}
	if (str[i])
		return (0);
	*result = (int)(num * sign);
	return (1);
}

static int	process_split(t_node **stack_a, char **tmp)
{
	int	j;
	t_node	*new_node;
	int	data;

	if (!tmp || !tmp[0])
		return (0);
	j = 0;
	while (tmp[j])
	{
		if (!safe_atoi(tmp[j], &data))
			return (0);
		new_node = node_new(data);
		if (!new_node)
			return (0);
		node_add_back(stack_a, new_node);
		j++;
	}
	return (1);
}

t_node	*init_stack(int argc, char **argv)
{
	int		i;
	char	**tmp;
	t_node	*stack_a;
	
	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!process_split(&stack_a, tmp))
		{
			free_all(tmp);
			free_stack(&stack_a);
			return (NULL);
		}
		free_all(tmp);
		i++;
	}
	if (!check_duplicates(stack_a))
	{
		free_stack(&stack_a);
		return (NULL);
	}
	return (stack_a);
}
