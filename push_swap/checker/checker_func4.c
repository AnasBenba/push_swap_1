/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:29:27 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:29:29 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 1 + i;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c && c[len])
		len++;
	return (len);
}

static char	*ft_join(char *ptr, const char *s1, const char *s2)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[y])
	{
		ptr[i + y] = s2[y];
		y++;
	}
	ptr[i + y] = '\0';
	return (ptr);
}

char	*ft_strjoin_get(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	ptr_len;

	if (!s1 && !s2)
		return (NULL);
	ptr_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(ptr_len + 2);
	if (!ptr)
		return (NULL);
	if (ptr_len == 0)
	{
		ptr[0] = '\0';
		return (ptr);
	}
	return (ft_join(ptr, s1, s2));
}
