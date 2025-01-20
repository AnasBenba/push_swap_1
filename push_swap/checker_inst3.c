/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_inst3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:31:20 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:31:22 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rrb(t_stack **b)
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
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
