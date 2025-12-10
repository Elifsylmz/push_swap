#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN (-2147483648)

char *join_args(int argc, char **argv);
char **get_numb(int argc, char **argv);
void parse_args(int argc, char **argv);

void check_numeric(char *str, char **numbers);
long ft_atol(const char *str);
void check_duplicate(long num, char **numbers, int index);

void free_split(char **split);
void err_exit(char **strings);

#endif