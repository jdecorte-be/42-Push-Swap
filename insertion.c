#include "pushswap.h"

//work
int	findmin(t_swap	*tab)
{
	t_list	*tmp = tab->stack_a;
	int		min = tmp->content;

	while(tmp)
	{
		if(tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return min;
}

void	insertion(t_swap *tab)
{
	int min = findmin(tab);
	t_list	*tmp = tab->stack_a;
	printf("x| %d |x ", tab->stack_a->content);

	while(tmp)
	{
		rotatea(tab);
		printf("| %d | ", tmp->content);
		tmp = tmp->next;
	}

}

