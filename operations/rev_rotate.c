/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:36:03 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/12/14 05:36:12 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate_one(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->bottom;
	stack->bottom = node->prev;
	stack->bottom->next = NULL;
	node->prev = NULL;
	node->next = stack->top;
	stack->top->prev = node;
	stack->top = node;
}

void	rra(t_stack *a)
{
	rev_rotate_one(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rev_rotate_one(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate_one(a);
	rev_rotate_one(b);
	write(1, "rrr\n", 4);
}
