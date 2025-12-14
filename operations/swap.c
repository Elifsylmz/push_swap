/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:36:18 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/12/14 05:36:52 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_one(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	stack->top = second;
	second->prev = NULL;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	else
		stack->bottom = first;
	second->next = first;
	first->prev = second;
}

void	sa(t_stack *a)
{
	swap_one(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_one(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_one(a);
	swap_one(b);
	write(1, "ss\n", 3);
}
