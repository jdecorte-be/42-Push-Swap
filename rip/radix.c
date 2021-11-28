#include "../pushswap.h"

// void sorting(t_swap *tab)
// {
//     int s_chunk[10];
//     int nchunk = 0;

//     int i;
//     int j = 0;
//     while(tab->stack_a->next->next)
//     {
//         int len = ft_lstsize(tab->stack_a);
//         int med = findmidval(tab->stack_a, 0);
//         int size = 0;
//         i = 0;
//         while(len--)
//         {
//             if(!(tab->stack_a->next->next))
//                 break;
//             if(tab->stack_a->content <= med)
//             {
//                 size++;
//                 push_b(tab);
//             }
//             else
//                 rotatea(tab);
//         }
//         s_chunk[j] = size;
//         j++;
//         nchunk++;
//     }
//     if (tab->stack_a->content > tab->stack_a->next->content)
//         swap_a(tab);
//     // printList(tab->stack_b);
//     // ----------------------------------------------------------------------------
//     printf("%d %d %d %d %d \n", s_chunk[0], s_chunk[1], s_chunk[2], s_chunk[3], s_chunk[4]);
// }

// int dec2bin(int num)
// {
//     int bin = 0, k = 1;

//     while (num)
//     {
//         bin += (num % 2) * k;
//         k *= 10;
//         num /= 2;
//     }

//     return bin;
// }

// int binaryexist(t_list *list, int i)
// {
//     t_list *tmp = list;
//     while(tmp)
//     {
//         if(((tmp->index >> i)&1) == 0)
//             return 1;
//         tmp = tmp->next;
//     }
//     return 0;
// }

void radix_sort(t_swap *tab)
{
    int len = ft_lstsize(tab->stack_a);
    int max_index = len - 1;
    int max_bits = 0;
    int i = 0;

    while((max_index >> max_bits) != 0)
        ++max_bits;
    while (i < max_bits)
    {
        int j = 0;
        while(j < len)
        {  
            int num = tab->stack_a->index;
            if ((((num >> i)&1) == 1))
                rotatea(tab);
            else
                push_b(tab);
            ++j;
        }
        while(tab->stack_b)
            push_a(tab);
        i++;
    }    
}

// int indexofmid(t_list *list, int mid)
// {
//     t_list *tmp = list;
//     int i = 0;
//     while(tmp)
//     {
//         if(tmp->index <= mid)
//             break;
//         i++;
//         tmp = tmp->next;
//     }
//     return i;
// }
// int findmidval(t_list *list, int to)
// {
//     t_list *tmp = list;
//     int res = 0;
//     int i = 0;

//     if(to == 0)
//         to = ft_lstsize(tmp);
//     while(i < to)
//     {
//         res += tmp->index;
//         i++;
//         tmp = tmp->next;
//     }
//     return res / to;
// }

// int nbrexist(t_list *list, int mid, int to)
// {
//     t_list *tmp = list;
//     int i = 0;
//     while(i < to && tmp)
//     {
//         if(tmp->index <= mid)
//             return 1;
//         i++;
//         tmp = tmp->next;
//     }
//     return 0;
// }

// int *mid_point_a(t_swap *tab)
// {   
//     int j = 0;
//     int *sizetab = malloc(sizeof(int) * 20);
//     int chunknbr;
//     int k = 0;
//     int max = 500;
//     while(tab->stack_a->next->next && tab->stack_a->next->next->next)
//     {
//         int len = ft_lstsize(tab->stack_a);
//         int midcontent = findmidval(tab->stack_a, len);
//         printf("mid = %d \n", midcontent);
//         int i = 0;
//         int chunk_size = 0;
//             while(i < len)
//             {
//                 int lenreset = ft_lstsize(tab->stack_a);
//                 int  mostclose = indexofmid(tab->stack_a, midcontent);
//                 if(tab->stack_a->index <= midcontent)
//                 {
//                     push_b(tab);
//                     chunk_size++;
//                 }
//                 else if (mostclose < lenreset / 2)
//                     rotatea(tab);
//                 else
//                     r_rotatea(tab);
//                 i++;
//             }
//             if(chunk_size < max)
//             {
//                 sizetab[k] = chunk_size;
//                 max = chunk_size;
//                 k++;
//                 printf("max = %d \n", chunk_size);
//                 chunknbr++;
//             }
//         j++;
//     }
//     sizetab[k] = 0;
//     int len = ft_lstsize(tab->stack_a);
//     if(len == 2)
//     {
//         if(tab->stack_a->content > tab->stack_a->next->content)
//             swap_a(tab);
//     }
//     if(len == 3)
//         sort_3nbr(tab);
//     k = 0;
//     tab->chunknbr = chunknbr;
//     return sizetab;
// }


// int *reversetab(int *chunksize)
// {
//     int i = 0;
//     int len = 0;
//     while(chunksize[len])
//         len++;
//     int *res = malloc(sizeof(int) * len);
//     int tmplen = len;
//     while(i < tmplen)
//     {
//         res[i] = chunksize[len - 1];
//         len--;
//         i++;
//     }
//     res[i] = 0;
//     return res;
// }

// void mid_point_b(t_swap *tab, int *chunksize)
// {
//     printf("chunknbr = %d \n",tab->chunknbr);
//     int i = 0;
//     while(i < tab->chunknbr)
//     {
//         printList(tab->stack_a);
//         int n = chunksize[i];
//         while(n)
//         {
//             int back = 0;
//             int mid = findmidval(tab->stack_b, n);
//             printf("SECOND MID = %d \n", mid);
//             if(n == 1)
//             {
//                 push_a(tab);
//                 n--;
//             }
//             if(n == 2)
//             {
//                 if(tab->stack_b->index < tab->stack_b->next->index)
//                     swap_b(tab);
//                 push_a(tab);
//                 push_a(tab);
//                 n-=2;
//             }
//             if(n == 3)
//             {
//                 while(n)
//                 {
//                     if(tab->stack_b->index > mid)
//                     {
//                         push_a(tab);
//                         n--;
//                         break;
//                     }
//                     else
//                     {
//                         rotateb(tab);
//                         back++;
//                     }
//                 }
//                 while(back--)
//                     r_rotateb(tab);
//             }
//             else
//             {
//                 int j =  0;
//                 int back = 0;
//                 int len = n;
//                 while(j < len)
//                 {
//                     if(tab->stack_b->index > mid)
//                     {
//                         push_a(tab);
//                         n--;
//                     }
//                     else
//                     {
//                         rotateb(tab);
//                         back++;
//                     }
//                     j++;
//                 }
//                 while(back--)
//                     r_rotateb(tab);
//             }
//         }
//         i++;
//     }
// }

// void radix_sort(t_swap *tab)
// {
//     int *chunksize = mid_point_a(tab);
//     chunksize = reversetab(chunksize);
//     int i = 0;
//     while (chunksize[i])
//     {
//         printf("%d ", chunksize[i]);
//         i++;
//     }
//     printf("\n");
//     mid_point_b(tab, chunksize);

//     chunksize = mid_point_a(tab);
//     chunksize = reversetab(chunksize);
//     mid_point_b(tab, chunksize);



//     free(chunksize);
// }