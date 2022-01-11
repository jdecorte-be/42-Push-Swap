/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:34:08 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 14:25:55 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap_a(t_swap *tab)
{
	t_list	*tmp;

	if (!tab->stack_a || !tab->stack_a->next)
		return ;
	tmp = tab->stack_a->next;
	tab->stack_a->next = tab->stack_a->next->next;
	tmp->next = tab->stack_a;
	tab->stack_a = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_swap *tab)
{
	t_list	*tmp;

	if (!tab->stack_b || !tab->stack_b->next)
		return ;
	tmp = tab->stack_b->next;
	tab->stack_b->next = tab->stack_b->next->next;
	tmp->next = tab->stack_b;
	tab->stack_b = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_swap *tab)
{
	swap_a(tab);
	swap_b(tab);
	ft_putstr_fd("ss\n", 1);
}

void	push_a(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_b))
		return ;
	tmp = (tab->stack_b)->next;
	(tab->stack_b)->next = (tab->stack_a);
	tab->stack_a = tab->stack_b;
	tab->stack_b = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_a))
		return ;
	tmp = (tab->stack_a)->next;
	(tab->stack_a)->next = (tab->stack_b);
	tab->stack_b = tab->stack_a;
	tab->stack_a = tmp;
	ft_putstr_fd("pb\n", 1);
}
