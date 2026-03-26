#include "push_swap.h"

int	safe_atoi(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (sign == 1 && num > INT_MAX)
			return (0);
		if (sign == -1 && -num < INT_MIN)
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	*result = (int)(num * sign);
	return (1);
}

t_node	*init_stack(int argc, char **argv)
{
	int		i;
	char	**tmp;
	t_node	*stack_a;
	t_node	*new_node;
	int		data;
	
	stack_a = NULL;
	data = 0;
	i = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (NULL);
	}
	else
	{
		i = 1;
		tmp = argv;
	}
	if (tmp == NULL)
		return (NULL);
	while (tmp[i])
	{
		if (!safe_atoi(tmp[i], &data))
		{
			if (argc == 2)
				ft_free(tmp);
			ft_lstdelone(&stack_a);
			return (NULL);
		}
		new_node = ft_lstnew(data);
		if (new_node == NULL)
		{
			if (argc == 2)
				ft_free(tmp);
			ft_lstdelone(&stack_a);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	if (argc == 2)
		ft_free(tmp);
	return(stack_a);
}
