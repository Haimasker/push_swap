/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:37:02 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/21 16:37:02 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack *stack, t_node *node1, t_node *node2)
{
	t_node	*prev;
	t_node	*next;

	prev = node1->prev;
	next = node2->next;
	prev->next = node2;
	node2->prev = prev;
	node1->next = next;
	next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
	stack->head = node2;
	if (stack->len == 2)
		stack->tail = node1;
}

void	swap(t_stack *stack1, t_stack *stack2, int id, t_cmd_list *list)
{
	t_node	*tmp;

	if (stack1 && (id == 1 || id == 3) && stack1->len >= 2)
		do_swap(stack1, stack1->head, stack1->head->next);
	if (stack2 && (id == 2 || id == 3) && stack2->len >= 2)
		do_swap(stack2, stack2->head, stack2->head->next);
	if (list && id == 3 && stack1->len >= 2 && stack2->len >= 2)
	{
		push_back_cmd(list, "ss\n");
		return ;
	}
	if (list && id == 1 && stack1->len >= 2)
		push_back_cmd(list, "sa\n");
	if (list && id == 2 && stack2->len >= 2)
		push_back_cmd(list, "sb\n");
}

void	push(t_stack *stack1, t_stack *stack2, int id, t_cmd_list *list)
{
	if (stack2 && stack1 && id == 1 && stack2->len > 0)
	{
		push_front(stack1, pop_front(stack2));
		if (list)
			push_back_cmd(list, "pa\n");
	}
	if (stack1 && stack2 && id == 2 && stack1->len > 0)
	{
		push_front(stack2, pop_front(stack1));
		if (list)
			push_back_cmd(list, "pb\n");
	}
}

void	rot(t_stack *stack1, t_stack *stack2, int id, t_cmd_list *list)
{
	if (stack1 && (id == 1 || id == 3) && stack1->len > 1)
		push_back(stack1, pop_front(stack1));
	if (stack2 && (id == 2 || id == 3) && stack2->len > 1)
		push_back(stack2, pop_front(stack2));
	if (list && id == 3 && stack1->len > 1 && stack2->len > 1)
	{
		push_back_cmd(list, "rr\n");
		return ;
	}
	if (list && id == 1 && stack1->len > 1)
		push_back_cmd(list, "ra\n");
	if (list && id == 2 && stack2->len > 1)
		push_back_cmd(list, "rb\n");
}

void	r_rot(t_stack *stack1, t_stack *stack2, int id, t_cmd_list *list)
{
	if (stack1 && stack1->head && (id == 1 || id == 3) && stack1->len > 1)
		push_front(stack1, pop_back(stack1));
	if (stack2 && stack2->head && (id == 2 || id == 3) && stack2->len > 1)
		push_front(stack2, pop_back(stack2));
	if (list && id == 3 && stack1->len > 1 && stack2->len > 1)
	{
		push_back_cmd(list, "rrr\n");
		return ;
	}
	if (list && id == 1 && stack1->len > 1)
		push_back_cmd(list, "rra\n");
	if (list && id == 2 && stack2->len > 1)
		push_back_cmd(list, "rrb\n");
}
