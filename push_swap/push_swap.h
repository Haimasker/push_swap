/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:35:08 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/20 14:35:08 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_node
{
	long long		value;
	struct s_node	*next;
	struct s_node	*prev;
	long long		index;
	int				keep;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	len;
	t_node	*mark;
	size_t	keep;
}	t_stack;

typedef struct s_cmd_node
{
	char				*value;
	struct s_cmd_node	*next;
}	t_cmd_node;

typedef struct s_cmd_list
{
	t_cmd_node	*head;
	size_t		len;
}	t_cmd_list;

typedef struct s_direction
{
	t_node	*a;
	t_node	*b;
	int		dir_a;
	int		dir_b;
	size_t	len;
	int		set;
}	t_direction;

t_node			*create_node(long long value);
t_stack			*create_stack(void);

void			push_front(t_stack *stack, t_node *node);
void			push_back(t_stack *stack, t_node *node);
t_node			*pop_front(t_stack *stack);
t_node			*pop_back(t_stack *stack);
void			list_free(t_stack *stack);

t_cmd_node		*create_cmd_node(char *value);
t_cmd_list		*create_cmd_list(void);

void			push_back_cmd(t_cmd_list *list, char *value);
void			list_free_cmd(t_cmd_list *list);
void			print_cmd(t_cmd_list *list1, t_cmd_list *list2);

t_direction		*create_direction(void);

void			do_swap(t_stack *stack, t_node *node1, t_node *node2);
void			swap(t_stack *st1, t_stack *st2, int id, t_cmd_list *list);
void			push(t_stack *st1, t_stack *st2, int id, t_cmd_list *list);
void			rot(t_stack *st1, t_stack *st2, int id, t_cmd_list *list);
void			r_rot(t_stack *st1, t_stack *st2, int id, t_cmd_list *list);

void			error_message(int state);

int				check_duplicates(t_stack *stack);
void			fill_args(int argc, char *argv[], t_stack *stack);

int				is_sorted(t_stack *stack);

static t_node	*get_next_node(t_stack *stack);
void			make_index(t_stack *stack);
size_t			index_mark(t_stack *stack, t_node *mark);
size_t			value_mark(t_stack *stack, t_node *mark);
void			set_mark(t_stack *stack, size_t (*mark)(t_stack *, t_node *));
int				need_push_b(t_stack *stack_a);
int				need_swap_a(t_stack *st, size_t (*mark)(t_stack *, t_node *));
void			process_a(t_stack *stack_a, t_stack *stack_b,
					size_t (*mark)(t_stack *, t_node *), t_cmd_list *cmd_list);

t_node			*find_node_a(t_stack *stack_a, int index);
void			calc_dir(t_stack *stack, int index,
					size_t *rx_len, size_t *rrx_len);
void			set_dir(size_t len, t_direction new_dir, t_direction *dir);
void			optimal_dir(t_stack *stack_a, t_stack *stack_b,
					t_node *node_b, t_direction *direction);
void			get_dir(t_stack *stack_a, t_stack *stack_b, t_direction *dir);
void			move_b(t_stack *stack_a, t_stack *stack_b,
					t_direction *dir, t_cmd_list *list);
void			process_b(t_stack *stack_a, t_stack *stack_b,
					t_cmd_list *list);

void			finish_a(t_stack *stack_a, t_cmd_list *list);
void			process_small(t_stack *stack_a, t_stack *stack_b,
					t_cmd_list *list);
t_cmd_list		*process(t_stack *stack_a,
					size_t (*mark)(t_stack *, t_node *), int argc);

char			*make_line(char **str, int chars, char **buf);
char			*get_next_line(int fd);
int				make_op(t_stack *stack_a, t_stack *stack_b, char *buf);
int				try_solve(t_stack *stack_a, t_stack *stack_b);

int				ft_isnumber(char *str);
long long		ft_atol(char *str);
size_t			ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
size_t			mxm(size_t a, size_t b);
char			*ft_strchr(char *s, int c);
char			*ft_strdup_gnl(char *s1);
char			*ft_substr_gnl(char *s, unsigned int start, size_t len);
char			*ft_strjoin_gnl(char *s1, char *s2);

#endif
