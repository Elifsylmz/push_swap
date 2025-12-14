#include "push_swap.h"

static int  find_min_pos(t_stack *a)
{
    t_node *tmp;
    int    	pos; 
    int	    bindex;
	int 	bposition;

	tmp = a->top;
	pos = 0;
	bindex = tmp->index;
	bposition = 0;
	while (tmp)
	{
		if (tmp->index < bindex)
		{
			bindex = tmp->index;
			bposition = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (bposition);
}

static void bring_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
}

static void sort_for_three(t_stack *a)
{
	int x;
	int y;
	int z;

	x = a->top->index;
	y = a->top->next->index;
	z = a->bottom->index;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void under_seven(t_stack *a, t_stack *b)
{
	int pos;

	if(a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_for_three(a);
		return ;
	}
	while (a->size > 3)
	{
		pos = find_min_pos(a);
		bring_to_top(a, pos);
		pb(a, b);
	}
	sort_for_three(a);
	while (b->size > 0)
		pa(a, b);
}