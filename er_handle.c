#include "push_swap.h"

void err_exit(void)
{
    write(2, "Error\n", 6);
    exit(2);
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