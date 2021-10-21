#include <stdio.h>
#include "includes/pushswap.h"
#include "libft/ft_atoi.c"
#include "libft/ft_strlen.c"
#include "libft/libft.h"
#include "libft/ft_lstadd_back.c"
#include "libft/ft_lstlast.c"
#include "libft/ft_lstsize.c"
#include "libft/ft_lstnew.c"

// print stack
void printList(t_list *head){
    t_list *tmp = head;

    while(tmp != NULL){
        printf("%d\n ", tmp->content);
        tmp = tmp->next;
    }
}

// create stack a and add number
t_list	*ft_init(t_list *lst, char **ag)
{
	t_list	*tmp;
    t_list *res;


    int i = 1;
    res = ft_lstnew(ft_atoi(ag[i]));
    i++;
	while (ag[i])
	{
        tmp = ft_lstnew(ft_atoi(ag[i]));
        ft_lstadd_back(&res, tmp);
        i++;
	}
	return (res);
}

int main(int ac, char **ag)
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = malloc(sizeof(t_list));
    stack_b = malloc(sizeof(t_list));
    stack_a = ft_init(stack_a, ag);
    printList(stack_a);


}