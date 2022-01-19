/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:52:29 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/16 01:10:18 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>

int lexer(char *input, t_swap *tab)
{
	if(ft_strcmp(input, "sa") == 0)
		swap_a(tab);
	else if(ft_strcmp(input, "sb") == 0)
		swap_b(tab);
	else if(ft_strcmp(input, "ss") == 0)
		ss(tab);
	else if(ft_strcmp(input, "pa") == 0)
		push_a(tab);
	else if(ft_strcmp(input, "pb") == 0)
		push_b(tab);
	else if(ft_strcmp(input, "ra") == 0)
		rotatea(tab);
	else if(ft_strcmp(input, "rb") == 0)
		rotateb(tab);
	else if(ft_strcmp(input, "rra") == 0)
		r_rotatea(tab);
	else if(ft_strcmp(input, "rrb") == 0)
		r_rotateb(tab);
	else
		return 0;
	return 1;
}

int	check_duplicate(char **ag, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		i = 0;
	while (ag[i])
	{
		if (ft_strlen(ag[i]) == 0)
			return (0);
		j = 1;
		if (ac == 2)
			j = 0;
		if (ft_atoi(ag[i]) > INT_MAX || ft_atoi(ag[i]) < INT_MIN)
			return (0);
		while (ag[j])
		{
			if (ft_atoi(ag[j]) == ft_atoi(ag[i]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_number(char **ag, int ac)
{
	int	i;
	int	j;
	int	nbr_count;

	i = 1;
	nbr_count = 0;
	if (ac == 2)
		i = 0;
	while (ag[i])
	{
		j = 0;
		while (ag[i][j])
		{
			if (!ft_isdigit(ag[i][j]) && ag[i][j] != ' ' && ag[i][j] != '-')
				return (0);
			else if (ft_isdigit(ag[i][j]))
				nbr_count++;
			j++;
		}
		i++;
	}
	if (nbr_count == 0)
		return (0);
	return (1);
}

t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	int		j;

	i = 1;
	if (ac == 2)
		i = 0;
	j = 0;
	res = ft_lstnew(ft_atoi(ag[i]));
	res->index = j;
	i++;
	while (ag[i])
	{
		tmp = ft_lstnew(ft_atoi(ag[i]));
		ft_lstadd_back(&res, tmp);
		j++;
		tmp->index = j;
		i++;
	}
	return (res);
}

int	main(int ac, char **ag)
{
	t_swap	*tab;

	if (ac == 2)
		ag = ft_split(ag[1], ' ');
	if (ac == 1)
		return (-1);
	if (!check_number(ag, ac) || !check_duplicate(ag, ac))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	tab->stack_a = ft_init(ag, ac);
	tab->stack_b = NULL;
	while(1)
	{
		char *input = get_next_line(1);
		if(!lexer(input, tab))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
	}
	if(issorted(tab->stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}