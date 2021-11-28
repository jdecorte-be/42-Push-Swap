#include <stdio.h>
#include "pushswap.h"

// print stack
void printList(t_list *head)
{
	t_list *tmp = head;

	while(tmp != NULL){
		printf(" %d|%d\\ ", tmp->content, tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
}

// create stack a and add number
t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list  *res;
	int i;
	if(ac == 2)
		i = 0;
	else
		i = 1;
	int j = 0;

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

int main(int ac, char **ag)
{

	t_swap  *tab;
	char **args;
	tab = malloc(sizeof(t_swap));

	if(ac == 2)
		args = ft_split(ag[1], ' ');
	else
		args = ag;
	tab->stack_a = ft_init(args, ac);
	tab->stack_tmp = ft_init(args, ac);
	free(args);
	int len = ft_lstsize(tab->stack_a);
	ft_sortindex(tab);
	ft_index_sorted(tab);
	free(tab->sorted);
	if(issorted(tab->stack_a) == 1)
		return 0;
	if(len == 5)
		sort_small(tab);
	else
		radix_sort(tab);
	
// // print res ---------------------------------
	// printList(tab->stack_a);
// 	printList(tab->stack_b);
// 	printf("|||| %d |||| \n", tab->ope);
}

//gcc main.c src/operations.c src/sort.c src/utils.c libft/libft.a