#include "../push_swap.h"

// rra rrb rrr

static void rev_rotate_one(t_stack *stack)
{
    t_node *node;

    if(!stack || stack->size < 2)
        return;
    node = stack->bottom;
    stack->bottom = node->prev;
    stack->bottom->next = NULL;
    node->prev = NULL;
    node->next = stack->top;
    stack->top->prev = node;
    stack->top = node;
}

void rra(t_stack *a)
{
    rev_rotate_one(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    rev_rotate_one(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    rev_rotate_one(a);
    rev_rotate_one(b);
    write(1, "rrr\n", 4);
}