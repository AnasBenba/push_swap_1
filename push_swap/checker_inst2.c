/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_inst2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:30:56 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:30:58 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || !(a->next))
		return ;
	tmp = a->number;
	a->number = a->next->number;
	a->next->number = tmp;
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	last->next = first;
	first->next = NULL;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || !(b->next))
		return ;
	tmp = b->number;
	b->number = b->next->number;
	b->next->number = tmp;
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	last->next = first;
	first->next = NULL;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!a || !(*a))
		return ;
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
}
