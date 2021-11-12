#include "../pushswap.h"

void    swap(t_swap *tab)
{

}

t_list *freeindex(t_swap *tab, int index)
{
    t_list *tmp = tab->stack_a;
    while(index-- && tmp)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    return tmp;
}

int find_min(t_swap *tab)
{
    t_list *tmp = tab->stack_a;
    int min = tmp->content;
    int index = 0;

    while(tmp->next)
    {
        if(min > tmp->next->content)
        {
            min = tmp->next->content;
            index = tmp->next->index;
        }
        tmp = tmp->next;
    }
    return index;
}

void ft_insertion(t_swap *tab)
{
    int i = 0;
    t_list *tmp = tab->stack_a;
    int index;
    int len = ft_lstsize(tmp);
    int *res = malloc(len * sizeof(char));
    while(tmp)
    {
        index = find_min(tab);

        printf("%d\n", index);
        res[i] = index;
        i++;
        tmp = tmp->next;
    }
}