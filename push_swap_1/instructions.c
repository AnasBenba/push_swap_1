#include "push_swap.h"

void    rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	temp = ft_lstlast(*a);
	before_last = *a;
	while (before_last->next != temp)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(&*a, temp);
	write(1, "rra\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *ptr;

    if (!b || !(*b))
        return;

    ptr = *b;
    if (!ptr)
        return ;
    *b = (*b)->next;

    if (!(*a))
    {
        *a = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = *a;
        *a = ptr;
    }

    write(1, "pa\n", 3);
}