/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope4_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:52:49 by decortejohn       #+#    #+#             */
/*   Updated: 2022/03/09 13:18:10 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rr(t_list **stack)
{
	t_list	*tmp;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_list **stack1)
{
	ft_rr(stack1);
}

void	rrb(t_list **stack2)
{
	ft_rr(stack2);
}
