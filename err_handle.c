#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	err_exit(char **strings)
{
	if (strings)
		free_split(strings);
	write(2, "Error\n", 6);
	exit(1);
}

void	err_exit_all(t_stack *a, t_stack *b, char **numbers)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (numbers)
		free_split(numbers);
	write(2, "Error\n", 6);
	exit(1);
}
