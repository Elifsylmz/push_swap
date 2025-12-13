#include "push_swap.h"

// set index 
// find target index
// set target

void set_index(t_stack *stack)
{
    t_node *current;
    int    i;

    if(!stack || stack->size == 0)
        return;
    i = 0;
    current = stack->top;
    while(current)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}

int get_smallest_index(t_stack *a)
{
    t_node *current;
    int min_value;
    int min_index;

    current = a->top;
    min_value = current->value;
    min_index = current->index;
    current = current->next;
    while(current)
    {
        if(current->value < min_value)
        {
            min_value = current->value;
            min_index = current->index;
        }
        current = current->next;
    }
    return (min_index);
}

int  find_target_index(t_stack *a, int b_value)
{
    t_node *current;
    int target_index;
    int target_value;
    int found;

    current = a->top;
    target_index = 0;
    target_value = 0;
    found = 0;
    while(current)
    {
        if(current->value > value && (!found || current->value < target_value))
        {
            target_value = current->value;
            target_index = current->index;
            found = 1;
        }
        current = current->next;
    }
    if(!found)
        target_index = get_smallest_index(a);
    return (target_index);
}

