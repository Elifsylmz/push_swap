#include "push_swap.h"

void debug_print_stack(t_stack *s)
{
    t_node *cur = s->top;
    while (cur)
    {
        ft_putnbr_fd(cur->value, 2);
        ft_putchar_fd(' ', 2);
        cur = cur->next;
    }
    ft_putchar_fd('\n', 2);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if(argc < 2)
        return(0);
    control(argc, argv);
    init_stack(&a);
    init_stack(&b);
    parse_args(argc, argv, &a);
    
    if(is_sorted(&a))
    {
        free_stack(&a);
        return (0);
    }
    debug_print_stack(&a);
    //sort(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return (0);
}
