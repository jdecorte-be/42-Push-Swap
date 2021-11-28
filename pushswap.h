#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include "libft/libft.h"

typedef struct s_swap
{
    t_list *stack_a;
    t_list *stack_b;
    t_list *stack_tmp;
    int chunknbr;
    int *sorted;
    int size;
}       t_swap;

void ft_index_replace(t_swap *tab, int index, int to);
void ft_index_sorted(t_swap *tab);
void indexremove(t_swap *tab, int index);
int find_min(t_swap *tab);
void ft_sortindex(t_swap *tab);

int	min(t_swap	*tab);


void	sort_3nbr(t_swap	*tab);
int findmidval(t_list *list, int to);
int	issorted(t_list	*stack);
void sorting(t_swap *tab);
void ft_index_replace(t_swap *tab, int index, int to);
void ft_index_sorted(t_swap *tab);
void ft_sortindex(t_swap *tab);
void swap_a(t_swap *tab);
void swap_b(t_swap *tab);
void push_a(t_swap *tab);
void push_b(t_swap *tab);
void rotatea(t_swap *tab);
void rotateb(t_swap *tab);
void r_rotatea(t_swap *tab);
void r_rotateb(t_swap *tab);
void radix_sort(t_swap *tab);

int	isrevsorted(t_swap	*tab);

void	sort_small(t_swap	*tab);
void printList(t_list *head);
void	insertion(t_swap *tab);


#endif // !PUSHSWAP_H
