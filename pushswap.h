#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include "libft/ft_atoi.c"
#include "libft/ft_strlen.c"
#include "libft/libft.h"
#include "libft/ft_lstadd_back.c"
#include "libft/ft_lstlast.c"
#include "libft/ft_lstsize.c"
#include "libft/ft_lstnew.c"

typedef struct s_swap
{
    int *stack_a;
    int *stack_b;
    int size;
}       t_swap;


#endif // !PUSHSWAP_H
