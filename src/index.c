#include "../pushswap.h"

void ft_index_replace(t_swap *tab, int index, int to)
{
    t_list *tmp = tab->stack_a;
    while(index-- && tmp)
        tmp = tmp->next;
    tmp->index = to;  
}

void ft_index_sorted(t_swap *tab)
{
    t_list *tmp = tab->stack_a;
    int i = 0;
    while (tmp)
    {
        ft_index_replace(tab, tab->sorted[i], i);
        i++;
        tmp = tmp->next;
    }
}

void indexremove(t_swap *tab, int index)
{
    t_list *tmp = tab->stack_tmp;
    while (tmp)
    {
        if(tmp->index == index)
            tmp->index = -1;
        tmp = tmp->next;
    }
}

int find_min(t_swap *tab)
{
    t_list *tmp = tab->stack_tmp;
    int min = 999999999;
    int index = 0;

    while(tmp)
    {
        if(min > tmp->content)
        {
            if(!(tmp->index == -1))
            {
                index = tmp->index;
                min = tmp->content;
            }
        }
        tmp = tmp->next;
    }
    indexremove(tab, index);
    return index;
}

void ft_sortindex(t_swap *tab)
{
    int i = 0;
    t_list *tmp = tab->stack_tmp;
    int index;
    int len = ft_lstsize(tmp);
    int *res = malloc(len * sizeof(int));

    while(len--)
    {
        index = find_min(tab);
        res[i] = index;
        i++;
        tmp = tmp->next;
    }
    tab->sorted = res;
}