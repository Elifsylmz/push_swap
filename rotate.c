#include "push_swap.h"

// ra rb rr

static void rotate_one(t_stack *stack)
{
    t_node *node;

    if(!stack || stack->size < 2)
        return;
    node = stack->top;;
    stack->top = node->next;
    stack->top->prev = NULL;
    node->next = NULL;
    node->prev = stack->bottom;
    stack->bottom->next = node;
    stack->bottom = node;
}

void ra(t_stack *a)
{
    rotate_one(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    rotate_one(b);
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate_one(a);
    rotate_one(b);
    write(1, "rr\n", 3);
}