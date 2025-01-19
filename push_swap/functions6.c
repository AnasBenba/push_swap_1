/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:06:19 by abenba            #+#    #+#             */
/*   Updated: 2025/01/18 13:06:20 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunck_check(size_t len)
{
	int	chunck;

	chunck = 0;
	if (len <= 100)
		chunck = 13;
	else
		chunck = 31;
	return (chunck);
}

void	few_arg(size_t len, t_stack **a)
{
	if (len == 2)
	{
		if ((*a)->number > (*a)->next->number)
			sa((*a), 0);
	}
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
}

int	sorted(t_stack **a)
{
	t_stack	*head;
	t_stack	*ptr;

	head = *a;
	while (head)
	{
		ptr = head->next;
		while (ptr)
		{
			if (head->number > ptr->number)
				return (1);
			ptr = ptr->next;
		}
		head = head->next;
	}
	return (0);
}

t_stack	*big_number(t_stack *a)
{
	t_stack	*ptr;
	int		tmp;

	ptr = a;
	tmp = a->number;
	while (a)
	{
		if (tmp < a->number)
		{
			tmp = a->number;
			ptr = a;
		}
		a = a->next;
	}
	return (ptr);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	while (*a && ft_lstsize(*a) > 3)
	{
		ptr = big_number(*a);
		while (*a != ptr)
		{
			fix_index(*a);
			up_or_down(*a);
			if (ptr->above_line == 1)
				ra(a, 0);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	ra(a, 0);
}
