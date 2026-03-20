#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		retrun (0);
	}
	a = init_stack(argc, argv)
	b = NULL;
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}