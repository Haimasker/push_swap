/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:46:40 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/21 16:46:40 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *stack)
{
	t_node	*cur;
	t_node	*tmp;

	cur = stack->head;
	while (cur != stack->tail)
	{
		tmp = cur->next;
		while (tmp != cur)
		{
			if (cur->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

void	fill_args(int argc, char *argv[], t_stack *stack)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		list_free(stack);
		exit(0);
	}
	while (argv[i] && ft_isnumber(argv[i]))
		i++;
	if (argv[i] != NULL)
		list_free(stack);
	error_message(argv[i] != NULL);
	i = 1;
	while (argv[i])
	{
		push_back(stack, create_node(ft_atol(argv[i++])));
		if (stack->tail->value > 2147483647ll || check_duplicates(stack))
		{
			list_free(stack);
			error_message(1);
		}
	}
}
