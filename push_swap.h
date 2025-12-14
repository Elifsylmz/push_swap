/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:36:39 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/12/14 05:36:39 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN (-2147483648)

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int			size;
	t_node		*top;
	t_node		*bottom;
}	t_stack;

int			is_space(char *str);
void		control(int argc, char **argv);
int			is_sorted(t_stack *a);

char		*join_args(int argc, char **argv);
char		**get_numb(int argc, char **argv);
void		parse_args(int argc, char **argv, t_stack *a);

int			check_numeric(char *str);
long		ft_atol(const char *str);
int			check_duplicate(t_stack *a, int num);

void		free_split(char **split);
void		error(void);
void		err_exit(char **strings);
void		err_exit_all(t_stack *a, t_stack *b, char **numbers);

void		init_stack(t_stack *stack);
int			push_stack_top(t_stack *stack, int value);
void		free_stack(t_stack *stack);

void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		index_stack(t_stack *a);
void		under_seven(t_stack *a, t_stack *b);
void		sort(t_stack *a, t_stack *b);
void		radix_sort(t_stack *a, t_stack *b);

#endif