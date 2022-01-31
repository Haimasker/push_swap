/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:36:36 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/21 19:36:36 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_next_node(t_stack *stack)
{
	size_t	i;
	int		has_min;
	t_node	*next_min;
	t_node	*cur;

	next_min = NULL;
	if (!stack)
		return (NULL);
	i = 0;
	has_min = 0;
	cur = stack->head;
	while (i < stack->len)
	{
		if ((cur->index == -1) && (!has_min || cur->value < next_min->value))
		{
			has_min = 1;
			next_min = cur;
		}
		i++;
		cur = cur->next;
	}
	return (next_min);
}

void	make_index(t_stack *stack)
{
	size_t	index;
	t_node	*cur;

	index = 0;
	cur = get_next_node(stack);
	while (cur)
	{
		cur->index = index++;
		cur = get_next_node(stack);
	}
}

size_t	index_mark(t_stack *stack, t_node *mark)
{
	long long	index;
	size_t		keep;
	t_node		*cur;

	keep = 0;
	if (stack && mark)
	{
		index = mark->index;
		mark->keep = 1;
		cur = mark->next;
		while (cur && cur != mark)
		{
			if (cur->index == index + 1)
			{
				keep++;
				index++;
				cur->keep = 1;
			}
			else
				cur->keep = 0;
			cur = cur->next;
		}
	}
	return (keep);
}

size_t	value_mark(t_stack *stack, t_node *mark)
{
	long long	index;
	size_t		keep;
	t_node		*cur;

	keep = 0;
	if (stack && mark)
	{
		index = mark->index;
		mark->keep = 1;
		cur = mark->next;
		while (cur && cur != mark)
		{
			if (cur->index > index)
			{
				keep++;
				index = cur->index;
				cur->keep = 1;
			}
			else
				cur->keep = 0;
			cur = cur->next;
		}
	}
	return (keep);
}

void	set_mark(t_stack *stack, size_t (*mark)(t_stack *, t_node *))
{
	size_t	i;
	size_t	cur_keep;
	t_node	*cur;

	if (!stack)
		return ;
	stack->keep = 0;
	i = 0;
	cur = stack->head;
	while (i < stack->len)
	{
		cur_keep = mark(stack, cur);
		if (cur_keep > stack->keep)
		{
			stack->mark = cur;
			stack->keep = cur_keep;
		}
		else if (cur_keep == stack->keep
			&& (!stack->mark || cur->value < stack->mark->value))
			stack->mark = cur;
		i++;
		cur = cur->next;
	}
	mark(stack, stack->mark);
}
