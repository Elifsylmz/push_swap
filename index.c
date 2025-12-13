#include "push_swap.h"

static int	*to_array(t_stack *a)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		err_exit_all(a, NULL, NULL);
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (arr);
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_stack *a)
{
	t_node	*tmp;
	int		*arr;
	int		idx;

	arr = to_array(a);
	bubble_sort(arr, a->size);
	tmp = a->top;
	while (tmp)
	{
		idx = find_index(arr, a->size, tmp->value);
		if (idx < 0)
		{
			free(arr);
			err_exit_all(a, NULL, NULL);
		}
		tmp->index = idx;
		tmp = tmp->next;
	}
	free(arr);
}
