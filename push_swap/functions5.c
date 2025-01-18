/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:07:06 by abenba            #+#    #+#             */
/*   Updated: 2025/01/18 13:07:07 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index_t = i;
		i++;
		stack = stack->next;
	}
}

int	*make_array(t_stack **a)
{
	t_stack	*ptr;
	int		i;
	int		len;
	int		*arr;

	len = ft_lstsize(*a);
	arr = malloc((len + 1) * sizeof(int));
	if (!arr)
		return (NULL);
	ptr = *a;
	i = 0;
	while (ptr)
	{
		arr[i] = ptr->number;
		i++;
		ptr = ptr->next;
	}
	return (arr);
}

void	sort_and_comp(int *arr, t_stack **a)
{
	int		i;
	int		len;
	t_stack	*ptr;

	len = ft_lstsize(*a);
	bubble_sort(arr, len);
	i = 0;
	ptr = *a;
	while (ptr)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == ptr->number)
			{
				ptr->index = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int chunck)
{
	while ((*a))
	{
		if ((*a)->index < ft_lstsize(*b))
		{
			pb(a, b);
			if (ft_lstsize(*b) > 1)
				rb(b, 0);
		}
		else if ((*a)->index < (ft_lstsize(*b) + chunck))
			pb(a, b);
		else
			ra(a, 0);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = NULL;
	while (*b)
	{
		ptr = big_index(*b);
		up_or_down(*b);
		while (*b != ptr)
		{
			if (ptr->above_line == 1)
				rb(b, 0);
			else
				rrb(b);
			fix_index(*b);
			up_or_down(*b);
		}
		pa(a, b);
	}
}
