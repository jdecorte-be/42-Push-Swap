/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:34:08 by decortejohn       #+#    #+#             */
/*   Updated: 2022/03/09 13:17:05 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_list **stack1, t_list **stack2)
{
	t_list	*push_b;

	if (!*stack2)
		return ;
	push_b = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = push_b;
}

void	pb(t_list **stack1, t_list **stack2)
{
	t_list	*push_a;

	if (!*stack1)
		return ;
	push_a = (*stack1)->next;
	(*stack1)->next = *stack2;
	*stack2 = *stack1;
	*stack1 = push_a;
}
