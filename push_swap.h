#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_node
{
	int	value;
	int	index;
	struct s_node	*next;
} t_node;

#endif