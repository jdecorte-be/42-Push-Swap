/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:48 by decortejohn       #+#    #+#             */
/*   Updated: 2022/01/07 15:37:53 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pushswap.h"

// print stack
void printList(t_list *head)
{
	t_list *tmp = head;

	while(tmp != NULL){
		printf(" %ld|%d\\ ", tmp->content, tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
}

// create stack a and add number
t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	int		j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
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
	char	**args;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	tab = malloc(sizeof(t_swap));
	if (ac == 2)
		args = ft_split(ag[1], ' ');
	else
		args = ag;
	tab->stack_a = ft_init(args, ac);
	tab->stack_b = NULL;
	tab->stack_tmp = ft_init(args, ac);
	ft_sortindex(tab);
	ft_index_sorted(tab);
	check_sort(tab);
}

// 2 63 28 23 99 3 29 29 11 41 66 37 22 60 21 5 91 95 47 37 8 98 38 36 65 40 87 99 36 69 26 71 43 59 53 49 60 19 66 17 33 89 62 81 68 77 29 89 57 75 78 97 29 53 45 83 25 36 44 99 17 55 89 47 33 21 27 76 88 31 49 95 91 63 54 11 0 67 35 2 87 85 28 70 0 40 78 75 36 12 35 97 9 38 5 40 35 34 41 96