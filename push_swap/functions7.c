/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:48 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 20:24:50 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_more_then_5(t_stack **a, t_stack **b, int chunck)
{
	int	*arr;

	arr = NULL;
	arr = make_array(a);
	if (arr)
	{
		sort_and_comp(arr, a);
		push_to_b(a, b, chunck);
		fix_index(*b);
		push_to_a(a, b);
		free(arr);
		return (0);
	}
	return (1);
}

void	free_all(char **s, char *j, t_stack **a)
{
	ft_free(s);
	free(j);
	ft_lstclear(a);
}
