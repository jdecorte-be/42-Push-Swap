/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:38:33 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/27 16:36:51 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	begin_sorting(t_list **stack1, t_list **stack2, t_push *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*stack1)->index <= push->mid)
			pb(stack1, stack2);
		else
		{
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (push->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	find_next(t_list **stack1, t_list **stack2, t_push *push)
{
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == push->next))
		pa(stack1, stack2);
	else if ((*stack1)->index == push->next)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		push->next++;
	}
	else if ((ft_lstsize(*stack2)) > 2
		&& ft_lstlast(*stack2)->index == push->next)
		rrb(stack2);
	else if ((*stack1)->next->index == push->next)
		sa(stack1);
	else if ((ft_lstsize(*stack1)) > 1 && ((*stack1)->next->index == push->next)
		&& ((*stack2)->next->index == push->next + 1))
		ss(stack1, stack2);
	else
		return ;
	find_next(stack1, stack2, push);
}

void	quick_a(t_list **stack1, t_list **stack2, t_push *push)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = ft_lstsize(*stack2);
	while (ft_lstsize(*stack2) && ++i < count_b)
	{
		if ((*stack2)->index == push->next)
			find_next(stack1, stack2, push);
		else if ((*stack2)->index >= push->mid)
		{
			(*stack2)->flag = push->flag;
			pa(stack1, stack2);
		}
		else if ((*stack2)->index < push->mid)
			rb(stack2);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	quick_b(t_list **stack1, t_list **stack2, t_push *push)
{
	int	now_flag;

	now_flag = (*stack1)->flag;
	if ((*stack1)->flag != 0)
	{
		while ((*stack1)->flag == now_flag)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, push);
		}
	}
	else if ((*stack1)->flag == 0)
	{
		while ((*stack1)->flag != -1)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, push);
		}
	}
	if (ft_lstsize(*stack2))
		push->max = (find_max_lst(stack2))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

void	quick_sort(t_list **stack1, t_list **stack2, int count)
{
	t_push	push;

	push.next = find_min_lst(stack1)->index;
	push.max = find_max_lst(stack1)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	begin_sorting(stack1, stack2, &push, count);
	while (!(check_sorting_a(stack1, count)))
	{
		if (ft_lstsize(*stack2) == 0)
			quick_b(stack1, stack2, &push);
		else
			quick_a(stack1, stack2, &push);
	}
}
