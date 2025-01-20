/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:29:46 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:29:51 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (s1)
	{
		ptr[i] = ' ';
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

char	*ft_strjoin(char const *s1, char const *s2)
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
