/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:51:10 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/22 10:51:10 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_small(t_stack *stack_a, t_stack *stack_b, t_cmd_list *list)
{
	push(stack_a, stack_b, 2, list);
	push(stack_a, stack_b, 2, list);
	if ((stack_a->head->index > stack_a->head->next->index
			&& stack_a->head->next->index > stack_a->tail->index)
		|| (stack_a->tail->index > stack_a->head->index
			&& stack_a->head->index > stack_a->head->next->index)
		|| (stack_a->head->next->index > stack_a->tail->index
			&& stack_a->tail->index > stack_a->head->index))
		swap(stack_a, stack_b, 1, list);
	if (stack_a->head->index > stack_a->head->next->index)
		rot(stack_a, stack_b, 1, list);
	if (stack_a->head->index > stack_a->tail->index)
		r_rot(stack_a, stack_b, 1, list);
}

void	finish_a(t_stack *stack_a, t_cmd_list *list)
{
	t_node	*cur;
	size_t	ra_len;
	size_t	rra_len;

	if (!stack_a || !stack_a->head)
		return ;
	ra_len = 0;
	cur = stack_a->head;
	while (cur && cur->index != 0)
	{
		ra_len++;
		cur = cur->next;
	}
	rra_len = 0;
	cur = stack_a->head;
	while (cur && cur->index != 0)
	{
		rra_len++;
		cur = cur->prev;
	}
	while (stack_a->head->index != 0 && (ra_len <= rra_len) && (ra_len--))
		rot(stack_a, NULL, 1, list);
	while (stack_a->head->index != 0 && (ra_len > rra_len) && (rra_len--))
		r_rot(stack_a, NULL, 1, list);
}

t_cmd_list	*process(t_stack *stack_a,
	size_t (*mark)(t_stack *, t_node *), int argc)
{
	t_cmd_list	*cmd_list;
	t_stack		*stack_b;

	cmd_list = create_cmd_list();
	stack_b = create_stack();
	if (!cmd_list || !stack_b)
	{
		list_free_cmd(cmd_list);
		list_free(stack_b);
		return (NULL);
	}
	if (argc == 6)
	{
		process_small(stack_a, stack_b, cmd_list);
		set_mark(stack_a, &index_mark);
	}
	else
		process_a(stack_a, stack_b, mark, cmd_list);
	process_b(stack_a, stack_b, cmd_list);
	finish_a(stack_a, cmd_list);
	list_free(stack_b);
	return (cmd_list);
}
