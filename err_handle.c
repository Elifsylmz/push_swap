#include "push_swap.h"

void    error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void err_exit(char **strings)
{
    if (strings)
        free_split(strings);
    write(2, "Error\n", 6);
    exit(1);
}

void free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}