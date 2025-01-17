#include "push_swap.h"

void sa(t_stack *a, int flag)
{
    int tmp;

    if (!a || !(a->next))
        return;

    tmp = a->number;
    a->number = a->next->number;
    a->next->number = tmp;
    if (flag == 0)
        write(1, "sa\n", 3);
}

void ra(t_stack **a, int flag)
{
    t_stack *first;
    t_stack *last;

    if (!a || !(*a) || !(*a)->next)
        return;

    first = *a;
    last = *a;

    while (last->next)
        last = last->next;

    *a = first->next;

    last->next = first;
    first->next = NULL;

    if (flag == 0)
        write(1, "ra\n", 3);
}

void sb(t_stack *b, int flag)
{
    int tmp;

    if (!b || !(b->next))
        return;

    tmp = b->number;
    b->number = b->next->number;
    b->next->number = tmp;
    if (flag == 0)
        write(1, "sb\n", 3);
}

void rb(t_stack **b, int flag)
{
    t_stack *first;
    t_stack *last;

    if (!b || !(*b) || !(*b)->next)
        return;

    first = *b;
    last = *b;

    while (last->next)
        last = last->next;

    *b = first->next;

    last->next = first;
    first->next = NULL;

    if (flag == 0)
        write(1, "rb\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *ptr;

    if (!a || !(*a))
        return;

    ptr = *a;
    if (!ptr)
        return ;
    *a = (*a)->next;

    if (!(*b))
    {
        *b = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = *b;
        *b = ptr;
    }

    write(1, "pb\n", 3);
}