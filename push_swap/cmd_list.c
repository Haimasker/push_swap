/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:32:21 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/22 10:32:21 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd_node	*create_cmd_node(char *value)
{
	t_cmd_node	*node;

	node = malloc(sizeof(t_cmd_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_cmd_list	*create_cmd_list(void)
{
	t_cmd_list	*list;

	list = malloc(sizeof(t_cmd_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->len = 0;
	return (list);
}

void	push_back_cmd(t_cmd_list *list, char *value)
{
	t_cmd_node	*node;
	t_cmd_node	*tmp;

	node = create_cmd_node(value);
	if (!node)
		return ;
	if (!list->len)
		list->head = node;
	else
	{
		tmp = list->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	list->len++;
}

void	list_free_cmd(t_cmd_list *list)
{
	t_cmd_node	*tmp;
	t_cmd_node	*tmp_next;

	if (!list)
		return ;
	tmp = list->head;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	free(list);
	list = NULL;
}

void	print_cmd(t_cmd_list *list1, t_cmd_list *list2)
{
	t_cmd_node	*tmp;

	if (list1->len >= list2->len)
		tmp = list1->head;
	else
		tmp = list2->head;
	while (tmp)
	{
		write(1, tmp->value, ft_strlen(tmp->value));
		tmp = tmp->next;
	}
	list_free_cmd(list1);
	list_free_cmd(list2);
}
