#include "push_swap.h"
void control()
{
    int i;
    
    i = 1;
    while(i < argc)
    {
        if(is_space(argv[i]) == 0)
            error();
        i++;
    }
    i = 1;
    while(i < argc)
    {
        if(argv[i][0] == '\0')
            error();
        i++;
    }
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
    parse_args(argc, argv);
    if(is_sorted(&a))
        return(0);
    sort(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return (0);
}
