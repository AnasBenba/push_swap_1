#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack	*ptr;
    int		i;

    i = 1;
    if (new)
    {
        if (!*lst)
        {
            *lst = new;
            return ;
        }
        ptr = *lst;
        while (ptr->next)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->next = new;
        new->index = i;
    }
}

t_stack *ft_lstnew(int number)
{
    t_stack *ptr;

    ptr = malloc(sizeof(t_stack));
    if (!ptr)
        return (NULL);
    ptr->number = number;
    ptr->next = NULL;
    ptr->index = 0;
    ptr->above_line = 0;
    ptr->index_t = 0;
    return (ptr);
}

void	ft_lstclear(t_stack **lst)
{
    t_stack	*ptr1;

    if (lst && *lst)
    {
        while ((*lst))
        {
            ptr1 = (*lst)->next;
            free((*lst));
            (*lst) = ptr1;
        }
        *lst = NULL;
    }
}

int	ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}

int	ft_isdigit(int c)
{
    return (c >= 48 && c <= 57);
}
