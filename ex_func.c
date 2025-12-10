#include "push_swap.h"



long ft_atol(const char *str)
{
    long result;
    int sign;
    int i;

    result = 0;
    siign = 1;
    i = 0;

    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    // tek + - kontrolü mü gerekli onu sor !!
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}