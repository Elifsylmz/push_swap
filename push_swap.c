#include "push_swap.h"

 void	sort(t_stack *a, t_stack *b)
{
	index_stack(a);
	if (a->size <= 7)
		under_seven(a, b);
	/*else
		radix_sort(a, b);*/
} 

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

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
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}