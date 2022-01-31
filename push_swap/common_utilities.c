/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:43:51 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/27 14:43:51 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(int state)
{
	if (!state)
		return ;
	write(2, "Error\n", 6);
	exit(0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	cur = stack->head;
	next = cur->next;
	while (next != stack->head)
	{
		if (cur->value > next->value)
			return (0);
		cur = cur->next;
		next = next->next;
	}
	return (1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (0);
	return (1);
}

long long	ft_atol(char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
		sign *= (44 - (long long)str[i++]);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10ll + (long long)(str[i++] - 48ll);
		if ((sign == 1 && res > 2147483647ll)
			|| (sign == -1 && res > 2147483648ll))
			return (3000000000ll);
	}
	return (res * sign);
}

size_t	ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
