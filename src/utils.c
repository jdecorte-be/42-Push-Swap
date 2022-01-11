/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:32:51 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 14:56:25 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	issorted(t_list	*stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	isrevsorted(t_swap	*tab)
{
	t_list	*tmp;

	tmp = tab->stack_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	findmidval(t_list *list, int to)
{
	t_list	*tmp;
	int		res;
	int		i;

	tmp = list;
	res = 0;
	i = 0;
	if (to == 0)
		to = ft_lstsize(tmp) - 1;
	while (i < to)
	{
		res += tmp->index;
		i++;
		tmp = tmp->next;
	}
	return (res / to);
}

int	indexofmid(t_list *list, int mid)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		if (tmp->index == mid)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}
