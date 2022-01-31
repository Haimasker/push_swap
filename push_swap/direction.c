/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:51:32 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/22 11:51:32 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_direction	*create_direction(void)
{
	t_direction	*direction;

	direction = (t_direction *)malloc(sizeof(t_direction));
	if (!direction)
		return (NULL);
	direction->a = NULL;
	direction->b = NULL;
	direction->dir_a = 0;
	direction->dir_b = 0;
	direction->len = 0;
	direction->set = 0;
	return (direction);
}

void	calc_dir(t_stack *stack, int index, size_t *rx_len, size_t *rrx_len)
{
	t_node	*cur;

	if (!stack || !stack->head)
		return ;
	cur = stack->head;
	while (cur->index != index)
	{
		(*rx_len)++;
		cur = cur->next;
	}
	cur = stack->head;
	while (cur->index != index)
	{
		(*rrx_len)++;
		cur = cur->prev;
		if (!cur)
			cur = stack->tail;
	}
}

void	set_dir(size_t len, t_direction new_dir, t_direction *dir)
{
	if (dir->set && len >= dir->len)
		return ;
	dir->a = new_dir.a;
	dir->b = new_dir.b;
	dir->dir_a = new_dir.dir_a;
	dir->dir_b = new_dir.dir_b;
	dir->len = len;
	dir->set = 1;
}

void	optimal_dir(t_stack *stack_a, t_stack *stack_b,
			t_node *node_b, t_direction *direction)
{
	t_direction	new_dir;
	size_t		ra_len;
	size_t		rra_len;
	size_t		rb_len;
	size_t		rrb_len;

	ra_len = 0;
	rra_len = 0;
	rb_len = 0;
	rrb_len = 0;
	new_dir.a = find_node_a(stack_a, node_b->index);
	new_dir.b = node_b;
	calc_dir(stack_a, new_dir.a->index, &ra_len, &rra_len);
	calc_dir(stack_b, node_b->index, &rb_len, &rrb_len);
	new_dir.dir_a = 0;
	new_dir.dir_b = 0;
	set_dir(mxm(ra_len, rb_len), new_dir, direction);
	new_dir.dir_a = 1;
	set_dir(rra_len + rb_len, new_dir, direction);
	new_dir.dir_b = 1;
	set_dir(mxm(rra_len, rrb_len), new_dir, direction);
	new_dir.dir_a = 0;
	set_dir(ra_len + rrb_len, new_dir, direction);
}

void	get_dir(t_stack *stack_a, t_stack *stack_b, t_direction *direction)
{
	size_t	i;
	t_node	*cur;

	if (!stack_b || !stack_a)
		return ;
	i = 0;
	cur = stack_b->head;
	while (i < stack_b->len)
	{
		optimal_dir(stack_a, stack_b, cur, direction);
		i++;
		cur = cur->next;
	}
}
