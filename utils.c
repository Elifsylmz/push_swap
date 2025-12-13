#include "push_swap.h"

int is_space(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] != ' ' && !(str[i] >= 9 && str[i] <=13))
            return (0);
        i++;
    }
    return (1);
}