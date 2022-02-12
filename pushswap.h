#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include "libft/libft.h"

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

typedef struct s_swap
{
    t_list  *stack_a;
    t_list  *stack_b;
    t_list  *stack_tmp;
    int     *sorted;
    int     pivot;
    int     asize;
    int     bsize;
}       t_swap;

// sort utils
int	check_sorting(t_list **stack1);
int	check_sorting_a(t_list **stack1, int count);
int	count_lst(t_list **stack);
t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);


// ope
void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);
void	ra(t_list **stack1);
void	rb(t_list **stack2);
void	rr(t_list **stack1, t_list **stack2);
void	sa(t_list **stack1);
void	sb(t_list **stack2);
void	ss(t_list **stack1, t_list **stack2);
void	rrb(t_list **stack2);




int	count_lst(t_list **stack);
void	check_sort(t_swap	*tab);
void	quick_sort(t_list **stack1, t_list **stack2, int count);
void		ft_ps_quick_b(t_swap *tab);
void ft_index_replace(t_swap *tab, int index, int to);
void ft_index_sorted(t_swap *tab);
void indexremove(t_swap *tab, int index);
int find_min(t_swap *tab);
void ft_sortindex(t_swap *tab);
int     quick_sort_a(t_swap *tab, int len);
int	min(t_swap	*tab);

void	sort_3nbr(t_swap	*tab);
int	issorted(t_list	*stack);
void sorting(t_swap *tab);
void ft_index_replace(t_swap *tab, int index, int to);
void ft_index_sorted(t_swap *tab);
void ft_sortindex(t_swap *tab);
void swap_a(t_swap *tab);
void swap_b(t_swap *tab);
void rotatea(t_swap *tab);
void rotateb(t_swap *tab);
void r_rotatea(t_swap *tab);
void r_rotateb(t_swap *tab);
void radix_sort(t_swap *tab);
void	sort_a(t_swap *tab, int start, int end);
int	isrevsorted(t_swap	*tab);

void	sort_small(t_swap	*tab);
void printList(t_list *head);
void	insertion(t_swap *tab);
void		quicksort_a(t_swap *tab);







void	quicksort_b(t_swap *tab);
int	findmidval(t_list *list, int to);
void	check_sort(t_swap	*tab);
int	indexofmid(t_list *list, int mid);

#endif // !PUSHSWAP_H
