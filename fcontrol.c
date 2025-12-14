#include "push_swap.h"

int	is_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

void	control(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_space(argv[i]))
			error();
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	t_node *current;

	if (a->size <= 1)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}