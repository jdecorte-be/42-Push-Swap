/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:52:29 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/27 14:58:09 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	lexer(char *input, t_swap *tab)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(&tab->stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(&tab->stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(&tab->stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(&tab->stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(&tab->stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(&tab->stack_b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}

int	ft_check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+')
					&& ft_isdigit(nbr[i + 1])) || ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (ag[i])
	{
		nbr = ft_atoi(ag[i]);
		if (!(nbr < INT_MAX && nbr > INT_MIN) || ft_check(res, nbr, ag[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

void	input(t_swap *tab)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!lexer(input, tab))
		{
			ft_putstr_fd("Error\n", 1);
			break ;
		}
		input = get_next_line(0);
	}
}

int	main(int ac, char **ag)
{
	t_swap	*tab;

	if (ac == 2)
		ag = ft_split(ag[1], ' ');
	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	tab->stack_b = NULL;
	tab->stack_a = ft_init(ag, ac);
	if (tab->stack_a == NULL)
		return (-1);
	input(tab);
	if (issorted(tab->stack_a) && !tab->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
