#include "pushswap.h"

void	addindex(t_swap *tab, int index)
{
	t_list	*tmp = tab->stack_a;
	while(index-- && tmp)
	{
		rotatea(tab);
		tmp = tmp->next;
	}
	push_b(tab);



}


void	radixsort(t_swap *tab)
{
	t_list	*tmp = tab->stack_a;
	while(tmp)
	{
	

		
		tmp = tmp->next;
	}



}

