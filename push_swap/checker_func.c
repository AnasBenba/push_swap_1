/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:30:15 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:30:16 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_arrlen(char **s)
{
	size_t	i;
	long	test;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		test = ft_atoi(s[i]);
		if (test > INT_MAX || test < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	for_norm(char **s, t_stack **a, t_stack **b, char *j)
{
	if (push_swap(s, a, b) == 1)
	{
		free_all(s, j, a);
		return (1);
	}
	return (0);
}
