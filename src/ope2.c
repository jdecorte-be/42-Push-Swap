/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:01:53 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/27 16:35:32 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_r(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **stack1)
{
	ft_r(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack2)
{
	ft_r(stack2);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack1, t_list **stack2)
{
	ft_r(stack1);
	ft_r(stack2);
	write(1, "rr\n", 3);
}
