/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:51:45 by decortejohn       #+#    #+#             */
/*   Updated: 2022/03/09 13:18:29 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_s(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **stack1)
{
	ft_s(stack1);
}

void	sb(t_list **stack2)
{
	ft_s(stack2);
}

void	ss(t_list **stack1, t_list **stack2)
{
	ft_s(stack1);
	ft_s(stack2);
}
