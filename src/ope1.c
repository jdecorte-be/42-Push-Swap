/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:34:08 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/12 16:50:00 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_list **stack1, t_list **stack2)
{
	t_list	*push_b;

	if (!(*stack2))
		return ;
	push_b = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = push_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack1, t_list **stack2)
{
	t_list	*push_a;

	if (!(*stack1))
		return ;
	push_a = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = push_a;
	write(1, "pb\n", 3);
}

