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
