#include "push_swap.h"

void check_numeric(char *str, char **numbers)
{
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        err_exit(numbers);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            err_exit(numbers);
        i++;
    }
}

long ft_atol(const char *str)
{
    long long limit;
    long result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    limit = (long long)INT_MAX;
    if (sign == -1)
        limit = (long long)INT_MAX + 1;
    while (str[i])
    {
        if (result > (limit - (str[i] - '0')) / 10)
            return (limit * sign + sign);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return ((long)(result * sign));
}

int check_duplicate (t_stack *a, int num)
{
    t_node *current;

    current = a->top;
    while (current)
    {
        if (current->value == num)
            return (1);
        current = current->next;
    }
    return (0);
}