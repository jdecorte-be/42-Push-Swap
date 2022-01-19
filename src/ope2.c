/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:01:53 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 14:25:31 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotatea(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_a) || !(tab->stack_a)->next)
		return ;
	tmp = tab->stack_a;
	while ((tab->stack_a)->next)
		tab->stack_a = (tab->stack_a)->next;
	(tab->stack_a)->next = tmp;
	tab->stack_a = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rotateb(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_b) || !(tab->stack_b)->next)
		return ;
	tmp = tab->stack_b;
	while ((tab->stack_b)->next)
		tab->stack_b = (tab->stack_b)->next;
	(tab->stack_b)->next = tmp;
	tab->stack_b = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	r_rotatea(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_a) || !(tab->stack_a)->next)
		return ;
	tmp = tab->stack_a;
	while ((tab->stack_a)->next->next)
		tab->stack_a = (tab->stack_a)->next;
	(tab->stack_a)->next->next = tmp;
	tmp = (tab->stack_a)->next;
	(tab->stack_a)->next = NULL;
	tab->stack_a = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	r_rotateb(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_b) || !(tab->stack_b)->next)
		return ;
	tmp = tab->stack_b;
	while ((tab->stack_b)->next->next)
		tab->stack_b = (tab->stack_b)->next;
	(tab->stack_b)->next->next = tmp;
	tmp = (tab->stack_b)->next;
	(tab->stack_b)->next = NULL;
	tab->stack_b = tmp;
	ft_putstr_fd("rrb\n", 1);
}
