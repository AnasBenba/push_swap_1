#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	if (lst)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void    rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	temp = ft_lstlast(*b);
	before_last = *b;
	while (before_last->next != temp)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_lstadd_front(&*b, temp);
	write(1, "rrb\n", 4);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a, 1);
    sb(b, 1);
    write(1, "ss\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    ra(a, 1);
    rb(b, 1);
    write(1, "rr\n", 3);
}
