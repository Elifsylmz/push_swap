#include "push_swap.h"

char *join_args(int argc, char **argv)
{
    char    *joined;
    char    *tmp;
    int     i;

    joined = ft_strdup(argv[1]);
    if (!joined)
        return (NULL);
    i = 2;
    while (i < argc)
    {
        tmp = ft_strjoin(joined, " ");
        if (!tmp)
        {
            free(joined);
            return (NULL);
        }
        free(joined);
        joined = ft_strjoin(tmp, argv[i]);
        free(tmp);
        if (!joined)
            return (NULL);
        i++;
    }
    return (joined);
}

char **get_numb(int argc, char **argv)
{
    char   *joined;
    char    **numbers;

    if(argc == 2)
    {
        numbers = ft_split(argv[1], ' ');
        if(!numbers)
            err_exit(NULL);
        return(numbers);
    }

    joined = join_args(argc, argv);
    if (!joined)
        err_exit(NULL);
    numbers = ft_split(joined, ' ');
    free(joined);
    if (!numbers || !numbers[0])
        err_exit(NULL);
    return (numbers);
}

void parse_args(int argc, char **argv)
{
    char    **numbers;
    int     i;
    long    num;

    numbers = get_numb(argc, argv);
    i = 0;
    while (numbers[i])
    {
        check_numeric(numbers[i], numbers);
        num = ft_atol(numbers[i]);
        if (num < INT_MIN || num > INT_MAX)
            err_exit(numbers);
        check_duplicate(num, numbers, i);
        i++;
    }
    free_split(numbers);
}
