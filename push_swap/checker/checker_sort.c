/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:32:56 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:32:58 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	use_instruction(char *inst, t_stack **a, t_stack **b)
{
	if (ft_strcmp(inst, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(inst, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(inst, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(inst, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(inst, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(inst, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(inst, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(inst, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(inst, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(inst, "pa\n") == 0)
		pa(a, b);
	else
		pb(a, b);
}

int	push_swap(char **s, t_stack **a, t_stack **b)
{
	int		test;
	char	*line;
	int		i;

	test = 0;
	i = 0;
	line = NULL;
	if (stack_init(a, s, test, i) == 1)
		return (1);
	line = get_next_line(0);
	while (line)
	{
		use_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (ft_lstsize(*b) == 0 && sorted(a) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
