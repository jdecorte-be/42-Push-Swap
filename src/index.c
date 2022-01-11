/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:00:35 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 14:28:16 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_index_replace(t_swap *tab, int index, int to)
{
	t_list	*tmp;

	tmp = tab->stack_a;
	while (index-- && tmp)
		tmp = tmp->next;
	tmp->index = to;
}

void	ft_index_sorted(t_swap *tab)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = tab->stack_a;
	while (tmp)
	{
		ft_index_replace(tab, tab->sorted[i], i);
		i++;
		tmp = tmp->next;
	}
}

void	indexremove(t_swap *tab, int index)
{
	t_list	*tmp;

	tmp = tab->stack_tmp;
	while (tmp)
	{
		if (tmp->index == index)
			tmp->index = -1;
		tmp = tmp->next;
	}
}

int	find_min(t_swap *tab)
{
	t_list		*tmp;
	long int	min;
	int			index;

	tmp = tab->stack_tmp;
	min = 9999999999999;
	index = 0;
	while (tmp)
	{
		if (min > tmp->content)
		{
			if (!(tmp->index == -1))
			{
				index = tmp->index;
				min = tmp->content;
			}
		}
		tmp = tmp->next;
	}
	indexremove(tab, index);
	return (index);
}

void	ft_sortindex(t_swap *tab)
{
	int		i;
	t_list	*tmp;
	int		index;
	int		len;
	int		*res;

	i = 0;
	tmp = tab->stack_tmp;
	len = ft_lstsize(tmp);
	res = malloc(len * sizeof(int));
	while (len--)
	{
		index = find_min(tab);
		res[i] = index;
		i++;
		tmp = tmp->next;
	}
	tab->sorted = res;
}
