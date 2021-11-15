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
    int *res = malloc(len * sizeof(char));

    while(len--)
    {
        index = find_min(tab);
        res[i] = index;
        i++;
        tmp = tmp->next;
    }
    tab->sorted = res;
}

int ft_indexchr(t_swap *tab, int index)
{
    t_list *tmp = tab->stack_a;
    int i = 0;
    while(tmp)
    {
        if(tmp->index == index)
            break;
        i++;
        tmp = tmp->next;
    }
    return i;
}



void sorting(t_swap *tab)
{
    // int maxindex = ft_lstsize(tab->stack_a);
    // int chunksize = maxindex / 2;
    // int len = chunksize;
    // int len2 = maxindex;
    // while(len2--)
    // {
    //     // x < 50
    //     if (tab->stack_a->index < chunksize)
    //         push_b(tab);
    // }
    // while(tab->stack_a)
    //     push_b(tab);

    // int i = maxindex - 1;
    // printf("%d\n", i);
    // int totallen;
    // while(tab->stack_b)
    // {
    //     totallen = ft_lstsize(tab->stack_b) / 2;
    //     if (ft_indexchr(tab, i) < totallen)
    //     {
    //         if(tab->stack_b->index == i)
    //         {
    //             push_a(tab);
    //             i--;
    //         }
    //         else
    //             rotateb(tab);
    //     }
    //     else
    //     {
    //         if(tab->stack_b->index == i)
    //         {
    //             push_a(tab);
    //             i--;
    //         }
    //         else
    //             r_rotateb(tab);
    //     }




    // }


































    int i = 0;
    int totallen;
    while(tab->stack_a)
    {
        totallen = ft_lstsize(tab->stack_a) / 2;
        // premier 5 < 3 
        if (ft_indexchr(tab, i) < totallen)
        {
            if(tab->stack_a->index == i)
            {
                push_b(tab);
                i++;
            }
            else
                rotatea(tab);
        }
        else
        {

            if(tab->stack_a->index == i)
            {
                push_b(tab);
                i++;
            }
            else
                r_rotatea(tab);
            
        }
    }






    while(tab->stack_b)
    {
        push_a(tab);
    }
}