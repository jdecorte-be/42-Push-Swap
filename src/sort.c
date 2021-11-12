#include "../pushswap.h"

void	sort_3nbr(t_swap	*tab)
{
	t_list	*last = ft_lstlast(tab->stack_a);

	if	(isrevsorted(tab) == 1)							// case 2
	{
		swap_a(tab);
		r_rotatea(tab);
	}
	else if (tab->stack_a->content < last->content && tab->stack_a->next->content < last->content)		// case 1
		swap_a(tab);
	else if (tab->stack_a->content > last->content && tab->stack_a->next->content < last->content)		// case 3
		rotatea(tab);
	else if (tab->stack_a->content < last->content && tab->stack_a->next->content > last->content)
	{
		swap_a(tab);
		rotatea(tab);
	}
	else if (tab->stack_a->content > last->content && tab->stack_a->next->content > last->content)
		r_rotatea(tab);
	printList(tab->stack_a);
}

void	sort_small(t_swap	*tab)
{
	if (ft_lstsize(tab->stack_a) <= 3)
		sort_3nbr(tab);
	else
	{
		push_b(tab);
		push_b(tab);
		sort_3nbr(tab);
	}
}
