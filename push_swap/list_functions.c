/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:25:57 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/21 16:25:57 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (stack && node)
	{
		if (!stack->len)
		{
			stack->head = node;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
			stack->tail = stack->head;
		}
		else
		{
			tmp = stack->head->prev;
			node->prev = tmp;
			tmp->next = node;
			node->next = stack->head;
			stack->head->prev = node;
			stack->head = node;
		}
		stack->len++;
	}
}

void	push_back(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (stack && node)
	{
		if (!stack->len)
		{
			stack->head = node;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
			stack->tail = stack->head;
		}
		else
		{
			tmp = stack->head->prev;
			node->prev = tmp;
			tmp->next = node;
			node->next = stack->head;
			stack->head->prev = node;
			stack->tail = node;
		}
		stack->len++;
	}
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*tmp;

	tmp = NULL;
	if (stack && stack->len)
	{
		if (stack->len == 1)
		{
			tmp = stack->head;
			stack->head = NULL;
			stack->tail = NULL;
			tmp->prev = tmp;
			tmp->next = tmp;
		}
		else
		{
			tmp = stack->head;
			stack->head = stack->head->next;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->prev = tmp;
			tmp->next = tmp;
		}
		stack->len--;
	}
	return (tmp);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*tmp;

	tmp = NULL;
	if (stack && stack->len)
	{
		if (stack->len == 1)
		{
			tmp = stack->head;
			stack->head = NULL;
			stack->tail = NULL;
			tmp->prev = tmp;
			tmp->next = tmp;
		}
		else
		{
			tmp = stack->tail;
			stack->tail = stack->tail->prev;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->prev = tmp;
			tmp->next = tmp;
		}
		stack->len--;
	}
	return (tmp);
}

void	list_free(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp_next;

	if (!stack)
		return ;
	tmp = stack->head;
	while (tmp != stack->tail)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	free(tmp);
	free(stack);
	stack = NULL;
}
