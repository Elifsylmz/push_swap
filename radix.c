#include "push_swap.h"

static int get_max_bits(int max)
{
    int bits;

    bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	i;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(a->size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		size = a->size;
		while (i++ < size)
		{
			if (((a->top->index >> bit) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
