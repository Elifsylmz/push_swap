#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	control(argc, argv);
	init_stack(&a);
	init_stack(&b);
	parse_args(argc, argv, &a);
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	// sort(&a, &b);
	index_numbers(t_stack * a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
