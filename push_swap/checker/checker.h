/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:30:36 by abenba            #+#    #+#             */
/*   Updated: 2025/01/19 16:30:39 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack
{
	int				number;
	int				index;
	int				index_t;
	int				above_line;
	struct s_stack	*next;
}					t_stack;

int					ft_lstsize(t_stack *lst);
long				ft_atoi(const char *str);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int number);
void				ft_lstclear(t_stack **lst);
int					ft_isprint(int c);
void				ft_free(char **ptr);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
int					is_valid(char **argv);
int					is_duplicate(char **argv);
size_t				ft_strlen(const char *c);
char				*ft_strjoin_get(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
int					push_swap(char **s, t_stack **a, t_stack **b);
size_t				ft_arrlen(char **s);
int					sorted(t_stack **a);
char				*get_next_line(int fd);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);

void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				ss(t_stack *a, t_stack *b);
void				rrb(t_stack **b);
void				rb(t_stack **b);
void				sb(t_stack *b);
void				rra(t_stack **a);
t_stack				*find_last(t_stack *stack);
void				ra(t_stack **a);
void				sa(t_stack *a);

#endif
