#include "push_swap.h"

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

int input_join(char **av, char **j)
{
    int		i;
	char	*t;

	i = 1;

	while (av[i])
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
            return(1);
		}
		free(t);
		i++;
    }
	return (0);
}

char **check_input(char **j, char **s)
{
	s = ft_split(*j, ' ');
	if (!s)
		return (NULL);
    if (!s || is_valid(s) == 0 || is_duplicate(s) == 0)
    {
        ft_free(s);
        free(*j);
        write(2, "Error\n", 6);
        return (NULL);
    }
	return (s);
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    char **s;
    char *j;

	(void)a;
	(void)b;
	j = NULL;
	s = NULL;
    if (argc == 1)
        return (0);
    if (input_join(argv, &j) == 1)
	{
		free(j);
		return (1);
	}
	s = check_input(&j, s);
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