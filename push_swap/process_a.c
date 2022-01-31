/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:15 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/22 10:59:15 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_push_b(t_stack *stack_a)
{
	size_t	i;
	t_node	*cur;

	if (!stack_a->head)
		return (0);
	i = 0;
	cur = stack_a->head;
	while (i < stack_a->len)
	{
		if (!cur->keep)
			return (1);
		i++;
		cur = cur->next;
	}
	return (0);
}

int	need_swap_a(t_stack *stack_a, size_t (*mark)(t_stack *, t_node *))
{
	size_t	keep;

	if (stack_a && stack_a->len >= 2)
	{
		swap(stack_a, NULL, 1, NULL);
		keep = mark(stack_a, stack_a->mark);
		swap(stack_a, NULL, 1, NULL);
		mark(stack_a, stack_a->mark);
		if (keep > stack_a->keep)
			return (1);
	}
	return (0);
}

void	process_a(t_stack *stack_a, t_stack *stack_b,
			size_t (*mark)(t_stack *, t_node *), t_cmd_list *cmd_list)
{
	stack_a->keep = mark(stack_a, stack_a->mark);
	while (need_push_b(stack_a))
	{
		if (need_swap_a(stack_a, mark))
		{
			swap(stack_a, NULL, 1, cmd_list);
			stack_a->keep = mark(stack_a, stack_a->mark);
		}
		else if (stack_a->head->keep == 0)
			push(stack_a, stack_b, 2, cmd_list);
		else
			rot(stack_a, stack_b, 1, cmd_list);
	}
}
