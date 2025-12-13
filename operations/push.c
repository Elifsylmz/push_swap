#include "../push_swap.h"

// pa pb

static void	push_one(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from || from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	node->next = to->top;
	node->prev = NULL;
	if (to->top)
		to->top->prev = node;
	else
		to->bottom = node;
	to->top = node;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b || b->size == 0)
		return ;
	push_one(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || a->size == 0)
		return ;
	push_one(a, b);
	write(1, "pb\n", 3);
}
