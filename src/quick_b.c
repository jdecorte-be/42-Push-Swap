/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:47:19 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/11 16:28:58 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	lefttosortforb(t_swap *tab, int pivot)
{
	t_list	*tmp;

	tmp = tab->stack_b;
	while (tmp)
	{
		if (tmp->index < pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	pushupper(t_swap *tab)
{
	int	i;

	i = 1;
	while (tab->stack_b)
	{
		if (tab->stack_b->index == ft_lstsize(tab->stack_b) - 1)
			push_a(tab);
		else if (indexofmid(tab->stack_b, ft_lstsize(tab->stack_b) - 1)
			< ft_lstsize(tab->stack_b) / 2)
			rotateb(tab);
		else
		{
			printf("%ld", ft_lstsize(tab->stack_b) - 1);
			printList(tab->stack_b);
			r_rotateb(tab);
		}
		i++;
	}
}

void	quicksort_b(t_swap *tab)
{
	int	pivot;

	while (ft_lstsize(tab->stack_b) > 1)
	{
		pivot = findmidval(tab->stack_b, 0);
		if (lefttosortforb(tab, pivot))
			pushupper(tab);
		else
			push_a(tab);
	}
}
