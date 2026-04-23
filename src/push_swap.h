#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
# include "libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#ifndef LONG_MAX
# define LONG_MAX 9223372036854775807L
#endif

#ifndef LONG_MIN
# define LONG_MIN (-LONG_MAX - 1L)
#endif

typedef struct	s_node
{
	int	value;
	int	index;
	int	push_cost;
	int	above_median;
	int cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
} t_node;

t_node	*init_stack(int argc, char **argv);
int		safe_atoi(char *str, int *result);
void	free_all(char **array);
int		free_stack(t_node **node);
int		check_duplicates(t_node *stack_a);
int		is_sorted(t_node *stack_a);
int		find_size(t_node *lst);
t_node	*node_new(int value);
t_node	*last_node(t_node *lst);
void	node_add_back(t_node **lst, t_node *new);
void	sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	push_swap(t_node **stack_a, t_node **stack_b);

#endif