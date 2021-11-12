#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include "libft/libft.h"

typedef struct s_swap
{
    t_list *stack_a;
    t_list *stack_b;
    int size;
}       t_swap;

void ft_insertion(t_swap *tab);
void swap_a(t_swap *tab);
void swap_b(t_swap *tab);
void push_a(t_swap *tab);
void push_b(t_swap *tab);
void rotatea(t_swap *tab);
void rotateb(t_swap *tab);
void r_rotatea(t_swap *tab);
void r_rotateb(t_swap *tab);

int	issorted(t_swap	*tab);
int	isrevsorted(t_swap	*tab);

void	sort_small(t_swap	*tab);
void printList(t_list *head);
void	insertion(t_swap *tab);


#endif // !PUSHSWAP_H
