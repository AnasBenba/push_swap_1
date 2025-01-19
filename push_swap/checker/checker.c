/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:28:12 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:28:13 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

int	input_join(char **av, char **j)
{
	int		i;
	int		len;
	char	*t;

	i = 1;
	len = ft_arrlen(av);
	while (i < len)
	{
		if (ft_strchr(av[i], '\n'))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		t = (*j);
		(*j) = ft_strjoin((*j), av[i]);
		if (!(*j))
		{
			free(t);
			return (1);
		}
		free(t);
		i++;
	}
	return (0);
}

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**check_input(char **j, char **av, size_t argc)
{
	char	**s;

	if (check_arg(av) == 0)
		return (NULL);
	if (input_join(av, j) == 1)
	{
		free(*j);
		return (NULL);
	}
	s = ft_split(*j, ' ');
	if (!s)
		return (NULL);
	if (!s || is_valid(s) == 0 || is_duplicate(s) == 0
		|| ft_arrlen(s) < argc - 1)
	{
		ft_free(s);
		free(*j);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (s);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**s;
	char	*j;

	a = NULL;
	b = NULL;
	j = NULL;
	s = NULL;
	if (argc == 1)
		return (0);
	s = check_input(&j, argv, (size_t)argc);
	if (s == NULL)
		return (1);
	if (ft_arrlen(s) < 1)
	{
		ft_free(s);
		free(j);
		return (1);
	}
	push_swap(s, &a, &b);
	ft_free(s);
	free(j);
	ft_lstclear(&a);
	return (0);
}
