/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:00:59 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 14:25:14 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	radix_sort(t_swap *tab)
{
	int		len;
	int		max_index;
	int		max_bits;
	int		i;
	int		j;
	int		num;

	max_bits = 0;
	len = ft_lstsize(tab->stack_a);
	max_index = len - 1;
	i = 0;
	while ((max_index >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			num = tab->stack_a->index;
			if (((num >> i) & 1) == 1)
				rotatea(tab);
			else
				push_b(tab);
			++j;
		}
		while (tab->stack_b)
			push_a(tab);
		i++;
	}
}

void	sort_3nbr(t_swap *tab)
{
	t_list	*last;

	if (issorted(tab->stack_a))
		return ;
	last = ft_lstlast(tab->stack_a);
	if (isrevsorted(tab))
	{
		swap_a(tab);
		r_rotatea(tab);
	}
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content < last->content)
		swap_a(tab);
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content < last->content)
		rotatea(tab);
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content > last->content)
	{
		swap_a(tab);
		rotatea(tab);
	}
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content > last->content)
		r_rotatea(tab);
}

void	sort_5nbr(t_swap	*tab)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			push_b(tab);
		else
			rotatea(tab);
		i++;
	}
	sort_3nbr(tab);
	push_a(tab);
	push_a(tab);
	if (tab->stack_a->content > tab->stack_a->next->content)
		swap_a(tab);
}

void	check_sort(t_swap	*tab)
{
	int	len;

	if (issorted(tab->stack_a))
		return ;
	len = ft_lstsize(tab->stack_a);
	if (len == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			swap_a(tab);
	}
	else if (len == 3)
		sort_3nbr(tab);
	else if (len == 5)
		sort_5nbr(tab);
	else if (len > 250)
		radix_sort(tab);
	else
		quicksort_a(tab);
}
