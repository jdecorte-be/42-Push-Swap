/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:00:59 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/27 16:42:13 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3nbr(t_swap *tab)
{
	t_list	*last;

	if (check_sorting(&tab->stack_a))
		return ;
	last = ft_lstlast(tab->stack_a);
	if (isrevsorted(tab))
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content < last->content)
		sa(&tab->stack_a);
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content < last->content)
		ra(&tab->stack_a);
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content > last->content)
	{
		sa(&tab->stack_a);
		ra(&tab->stack_a);
	}
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content > last->content)
		rra(&tab->stack_a);
}

void	sort_5nbr(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	while (len--)
	{
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			pb(&tab->stack_a, &tab->stack_b);
		else
			ra(&tab->stack_a);
	}
	sort_3nbr(tab);
	pa(&tab->stack_a, &tab->stack_b);
	pa(&tab->stack_a, &tab->stack_b);
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a);
}

void	check_sort(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (check_sorting(&tab->stack_a))
		return ;
	if (len == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	else if (len == 3)
		sort_3nbr(tab);
	else if (len == 5)
		sort_5nbr(tab);
	else
		quick_sort(&tab->stack_a, &tab->stack_b, ft_lstsize(tab->stack_a));
}
