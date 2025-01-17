#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct s_stack
{
    int number;
    int index;
    int index_t;
    int above_line;
    struct s_stack *next;
} t_stack;

int	ft_lstsize(t_stack *lst);
long	ft_atoi(const char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack *ft_lstnew(int number);
void	ft_lstclear(t_stack **lst);
int	ft_isprint(int c);
void	ft_free(char **ptr);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
int is_valid(char **argv);
int is_duplicate(char **argv);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strcmp(const char *s1, const char *s2);
void sort_3(t_stack **a);
t_stack *big_index(t_stack *a);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int push_swap(char **s, t_stack **a, t_stack **b);
size_t ft_arrlen(char **s);
void up_or_down(t_stack *stack);
void bubbleSort(int arr[], int n);
int *make_array(t_stack **a);
void sort_and_comp(int *arr, t_stack **a);
void push_to_b(t_stack **a, t_stack **b, int chunck);
void push_to_a(t_stack **a, t_stack **b);
void fix_index(t_stack *stack);
int chunck_check(size_t len);
int sorted(t_stack **a);
void few_arg(size_t len, t_stack **a);


void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void ss(t_stack *a, t_stack *b);
void rrb(t_stack **b);
void rb(t_stack **b, int flag);
void sb(t_stack *b, int flag);
void    rra(t_stack **a);
t_stack *find_last(t_stack *stack);
void ra(t_stack **a, int flag);
void sa(t_stack *a, int flag);


#endif