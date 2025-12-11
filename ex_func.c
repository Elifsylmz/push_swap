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
    long result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;

    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

void check_duplicate (long num, char **numbers, int index)
{
    // stack oluşturunca bunu orda kullanabilirsin
    // tekrar tek ft_atol çağırmak yerine iyi olur
    int j;

    if(index == 0)
        return;
    j = index - 1;
    while(j >= 0)
    {
        if(ft_atol(numbers[j]) == num)
            err_exit(numbers);
        j--;
    }
}