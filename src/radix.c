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

int findmidval(t_list *list, int to)
{
    t_list *tmp = list;
    int res = 0;
    int i = 0;

    if(to == 0)
        to = ft_lstsize(tmp);
    while(i < to)
    {
        res += tmp->content;
        i++;
        tmp = tmp->next;
    }
    return res / to;
}

void sorting(t_swap *tab)
{
    int s_chunk[10];
    int nchunk = 0;

    int i;
    int j = 0;
    while(tab->stack_a->next->next)
    {
        int len = ft_lstsize(tab->stack_a);
        int med = findmidval(tab->stack_a, 0);
        int size = 0;
        i = 0;
        while(len--)
        {
            if(!(tab->stack_a->next->next))
                break;
            if(tab->stack_a->content <= med)
            {
                size++;
                push_b(tab);
            }
            else
                rotatea(tab);
        }
        s_chunk[j] = size;
        j++;
        nchunk++;
    }
    if (tab->stack_a->content > tab->stack_a->next->content)
        swap_a(tab);
    // printList(tab->stack_b);
    // ----------------------------------------------------------------------------
    printf("%d %d %d %d %d \n", s_chunk[0], s_chunk[1], s_chunk[2], s_chunk[3], s_chunk[4]);
}

int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}

void quicksort(t_swap *tab)
{}


void radix_sort(t_swap *tab)
{
    int len = ft_lstsize(tab->stack_a);
    int max_index = len - 1;
    int max_bits = 0;
    int i = 0;

    while((max_index >> max_bits) != 0)
        ++max_bits;
    for (int i = 0 ; i < max_bits ; ++i)
    {
        for(int j = 0 ; j < len ; ++j)
        {
            int num = tab->stack_a->index;
            if ((((num >> i)&1) == 1))
                rotatea(tab);
            else
                push_b(tab);
        }
    while (tab->stack_b)
        push_a(tab);
    }

}