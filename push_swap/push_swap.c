/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:57:57 by abenba            #+#    #+#             */
/*   Updated: 2025/01/18 12:58:00 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack **a, char **s, long test, int i)
{
	t_stack	*ptr;

	while (s[i])
	{
		test = ft_atoi(s[i]);
		if (test > INT_MAX || test < INT_MIN)
		{
			ft_free(s);
			ft_lstclear(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		ptr = ft_lstnew((int)test);
		if (!ptr)
		{
			ft_free(s);
			ft_lstclear(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(a, ptr);
		i++;
	}
	return (0);
}

void	sort_3(t_stack **a)
{
	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	while (1)
	{
		if (((*a)->number > (*a)->next->number)
			&& ((*a)->number > (*a)->next->next->number))
			ra(a, 0);
		else if ((*a)->number > (*a)->next->number)
			sa((*a), 0);
		else if (((*a)->next->number > (*a)->number)
			&& ((*a)->next->number > (*a)->next->next->number))
			rra(a);
		else
			break ;
	}
}

void	bubble_sort(int arr[], int n)
{
	int	swapped;
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

void	up_or_down(t_stack *stack)
{
	int	line;

	if (stack == NULL)
		return ;
	line = ft_lstsize(stack) / 2;
	while (stack)
	{
		if (stack->index_t <= line)
			stack->above_line = 1;
		else
			stack->above_line = 0;
		stack = stack->next;
	}
}

int	push_swap(char **s, t_stack **a, t_stack **b)
{
	int	chunck;
	int	test;
	int	*arr;
	int	i;

	test = 0;
	i = 0;
	arr = NULL;
	chunck = chunck_check(ft_arrlen(s));
	if (stack_init(a, s, test, i) == 1)
		return (1);
	if (sorted(a) == 0)
		return (0);
	else if (ft_lstsize(*a) == 2 || ft_lstsize(*a) == 3)
		few_arg(ft_lstsize(*a), a);
	else
	{
		arr = make_array(a);
		sort_and_comp(arr, a);
		push_to_b(a, b, chunck);
		fix_index(*b);
		push_to_a(a, b);
	}
	return (0);
}
