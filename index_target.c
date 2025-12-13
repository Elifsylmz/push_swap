#include "push_swap.h"

int    find_index(t_node *a, int *arr, int size)
{
    int i;
    t_node *temp;

    i = 0;
    temp = a;
    while (temp)
    {
        if (temp->value == arr[i])
            return (i);
        i++;
    }
    return (-1);
}
void    sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	if (!arr || size <= 0)
		return (arr);
	j = 0;
	i = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (arr);
}

int *to_array(t_node *a, int size)
{
    t_node *temp;
    int *arr;
    int i;

    i = 0;
    temp = a;
    arr = malloc(size * sizeof(int));
    while (temp)
    {
        arr[i] = temp->value;
        i++;
        temp = temp->value;
    }
    return (arr);
}

void    index_numbers(t_node *a)
{
    t_node *temp;
    int     *arr;

    temp = a;
    arr = to_array(a, a->size);
    sort_array(arr, a->size);
    while (temp)
    {
        temp->value = find_index(a, arr, a->size);
        temp = temp->next;
    }
}
