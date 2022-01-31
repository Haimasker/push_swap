/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:38:28 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/21 16:38:28 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_cmd_list	*cmd_list_index;
	t_cmd_list	*cmd_list_value;

	stack_a = create_stack();
	error_message(!stack_a);
	fill_args(argc, argv, stack_a);
	if (is_sorted(stack_a))
	{
		list_free(stack_a);
		exit(0);
	}
	make_index(stack_a);
	set_mark(stack_a, &index_mark);
	cmd_list_index = process(stack_a, &index_mark, argc);
	list_free(stack_a);
	stack_a = create_stack();
	error_message(!stack_a);
	fill_args(argc, argv, stack_a);
	make_index(stack_a);
	set_mark(stack_a, &value_mark);
	cmd_list_value = process(stack_a, &value_mark, argc);
	list_free(stack_a);
	print_cmd(cmd_list_index, cmd_list_value);
	return (0);
}
