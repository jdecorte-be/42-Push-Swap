#include "../pushswap.h"

int	max(t_swap	*tab)
{
	t_list	*tmp = tab->stack_a;
	int		max;

	while(tmp)
	{
		if(tmp->content > tmp->next->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return max;
}

int nbrdig(t_swap	*tab)
{
	int	nbr = max(tab);
	int count = 0;

	while (nbr)
	{
		count++;
		nbr = nbr / 10;
	}
	return count;
}

int	issorted(t_swap	*tab)
{
	t_list	*tmp = tab->stack_a;
	while(tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}

int	isrevsorted(t_swap	*tab)
{
	t_list	*tmp = tab->stack_a;
	while(tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}