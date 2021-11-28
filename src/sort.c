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
}

void	sort_small(t_swap	*tab)
{
	int len = ft_lstsize(tab->stack_a);
	if(len == 2)
	{
		if(tab->stack_a->content > tab->stack_a->next->content)
			swap_a(tab);
	}
	else if (len == 3)
		sort_3nbr(tab);
	else if (len == 5)
	{
		int i = 0;
		while(i < 5)
		{
			if(tab->stack_a->index == 0 || tab->stack_a->index == 1)
				push_b(tab);
			else
				rotatea(tab);
			i++;
		}
		sort_3nbr(tab);
		push_a(tab);
		push_a(tab);
		if(tab->stack_a->content > tab->stack_a->next->content)
			swap_a(tab);
	}
}

void radix_sort(t_swap *tab)
{
    int len = ft_lstsize(tab->stack_a);
    int max_index = len - 1;
    int max_bits = 0;
    int i = 0;

    while((max_index >> max_bits) != 0)
        ++max_bits;
    while (i < max_bits)
    {
        int j = 0;
        while(j < len)
        {  
            int num = tab->stack_a->index;
            if ((((num >> i)&1) == 1))
                rotatea(tab);
            else
                push_b(tab);
            ++j;
        }
        while(tab->stack_b)
            push_a(tab);
        i++;
    }    
}
