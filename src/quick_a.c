/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:38:33 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 15:00:20 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	lefttosortfora(t_swap *tab, int pivot)
{
	t_list	*tmp;

	tmp = tab->stack_a;
	while (tmp)
	{
		if (tmp->index > pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	pushlower(t_swap *tab, int pivot)
{
	int	i;
	int	len;

	len = ft_lstsize(tab->stack_a);
	i = 1;
	while (i < len)
	{
		if (tab->stack_a->index < pivot)
			push_b(tab);
		else
			rotatea(tab);
		i++;
	}
}

void	quicksort_a(t_swap *tab)
{
	int	pivot;

	while (ft_lstsize(tab->stack_a) > 0)
	{
		pivot = findmidval(tab->stack_a, 0);
		if (issorted(tab->stack_a) == 1)
			break ;
		if (lefttosortfora(tab, pivot))
			pushlower(tab, pivot);
		else
			push_b(tab);
	}
	quicksort_b(tab);
}
