#include "../pushswap.h"

//sa
void swap_a(t_swap *tab)
{
    t_list *tmp;

    if (!tab->stack_a || !tab->stack_a->next)
        return ;
    tmp = tab->stack_a->next;
    tab->stack_a->next = tab->stack_a->next->next;
    tmp->next = tab->stack_a;
    tab->stack_a = tmp;
    printf("sa\n");
}

//sb
void swap_b(t_swap *tab)
{
    t_list *tmp;

    if (!tab->stack_b || !tab->stack_b->next)
        return ;
    tmp = tab->stack_b->next;
    tab->stack_b->next = tab->stack_b->next->next;
    tmp->next = tab->stack_b;
    tab->stack_b = tmp;
    printf("sb\n");
}

//ss
void ss(t_swap *tab)
{
    swap_a(tab);
    swap_b(tab);
    printf("ss\n");
}

//pa
void push_a(t_swap *tab)
{
    t_list	*tmp;

	if (!(tab->stack_b))
		return ;
	tmp = (tab->stack_b)->next;
	(tab->stack_b)->next = (tab->stack_a);
	tab->stack_a = tab->stack_b;
	tab->stack_b = tmp;
    printf("pa\n");
}

//pb
void push_b(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_a))
		return ;
	tmp = (tab->stack_a)->next;
	(tab->stack_a)->next = (tab->stack_b);
	tab->stack_b = tab->stack_a;
	tab->stack_a = tmp;
    printf("pb\n");
}

void rotatea(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_a) || !(tab->stack_a)->next)
		return ;
	tmp = tab->stack_a;
	while ((tab->stack_a)->next)
		tab->stack_a = (tab->stack_a)->next;
	(tab->stack_a)->next = tmp;
	tab->stack_a = tmp->next;
	tmp->next = NULL;
    printf("ra\n");
}

void rotateb(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_b) || !(tab->stack_b)->next)
		return ;
	tmp = tab->stack_b;
	while ((tab->stack_b)->next)
		tab->stack_b = (tab->stack_b)->next;
	(tab->stack_b)->next = tmp;
	tab->stack_b = tmp->next;
	tab->stack_b = NULL;
    printf("ra\n");
}

void r_rotatea(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_a) || !(tab->stack_a)->next)
		return ;
	tmp = tab->stack_a;
	while ((tab->stack_a)->next->next)
		tab->stack_a = (tab->stack_a)->next;
	(tab->stack_a)->next->next = tmp;
	tmp = (tab->stack_a)->next;
	(tab->stack_a)->next = NULL;
	tab->stack_a = tmp;
}

void r_rotateb(t_swap *tab)
{
	t_list	*tmp;

	if (!(tab->stack_b) || !(tab->stack_b)->next)
		return ;
	tmp = tab->stack_b;
	while ((tab->stack_b)->next->next)
		tab->stack_b = (tab->stack_b)->next;
	(tab->stack_b)->next->next = tmp;
	tmp = (tab->stack_b)->next;
	(tab->stack_b)->next = NULL;
	tab->stack_b = tmp;
}