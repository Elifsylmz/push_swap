#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->target_i = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	push_stack_top(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return (0);
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}