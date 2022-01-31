/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:56:50 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/22 11:56:50 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_node_a(t_stack *stack_a, int index)
{
	t_node	*cur;

	cur = stack_a->mark;
	if (index < cur->index)
	{
		while (index < cur->prev->index && cur->index > cur->prev->index)
			cur = cur->prev;
	}
	else
	{
		while (index > cur->index && cur->index < cur->next->index)
			cur = cur->next;
		if (index > cur->index && cur->index > cur->next->index)
			cur = cur->next;
	}
	return (cur);
}

void	move_b(t_stack *stack_a, t_stack *stack_b,
			t_direction *dir, t_cmd_list *list)
{
	while (dir->a != stack_a->head || dir->b != stack_b->head)
	{
		if (dir->dir_a == dir->dir_b
			&& dir->a != stack_a->head && dir->b != stack_b->head)
		{
			if (dir->dir_a == 0)
				rot(stack_a, stack_b, 3, list);
			else
				r_rot(stack_a, stack_b, 3, list);
		}
		else if (dir->a != stack_a->head)
		{
			if (dir->dir_a == 0)
				rot(stack_a, stack_b, 1, list);
			else
				r_rot(stack_a, stack_b, 1, list);
		}
		else if (dir->b != stack_b->head)
		{
			if (dir->dir_b == 0)
				rot(stack_a, stack_b, 2, list);
			else
				r_rot(stack_a, stack_b, 2, list);
		}
	}
}

void	process_b(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	t_direction	*direction;

	direction = create_direction();
	if (!direction)
		return ;
	while (stack_b->len)
	{
		direction->set = 0;
		get_dir(stack_a, stack_b, direction);
		move_b(stack_a, stack_b, direction, list);
		push(stack_a, stack_b, 1, list);
	}
	free(direction);
}
