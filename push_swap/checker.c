/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:15:29 by lumfred           #+#    #+#             */
/*   Updated: 2022/01/27 14:15:29 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*make_line(char **str, int chars, char **buf)
{
	int		index;
	char	*line;
	char	*tmp;

	free(*buf);
	tmp = NULL;
	if (chars < 0 || *str == NULL)
		return (NULL);
	if (!chars && !ft_strchr(*str, '\n'))
	{
		line = ft_strdup_gnl(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	index = 0;
	while ((*str)[index] != '\n')
		index++;
	line = ft_substr_gnl(*str, 0, index + 1);
	if ((int)ft_strlen(*str) - index - 1 >= 1)
		tmp = ft_substr_gnl(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*tmp;
	int			chars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	chars = read(fd, buf, BUFFER_SIZE);
	while (chars > 0)
	{
		buf[chars] = '\0';
		if (!str)
			tmp = ft_strdup_gnl(buf);
		else
			tmp = ft_strjoin_gnl(str, buf);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
		chars = read(fd, buf, BUFFER_SIZE);
	}
	return (make_line(&str, chars, &buf));
}

int	make_op(t_stack *stack_a, t_stack *stack_b, char *buf)
{
	if (ft_strlen(buf) == 3 && !ft_strncmp("pa\n", buf, 3))
		push(stack_a, stack_b, 1, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("pb\n", buf, 3))
		push(stack_a, stack_b, 2, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("sa\n", buf, 3))
		swap(stack_a, stack_b, 1, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("sb\n", buf, 3))
		swap(stack_a, stack_b, 2, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("ss\n", buf, 3))
		swap(stack_a, stack_b, 3, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("ra\n", buf, 3))
		rot(stack_a, stack_b, 1, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("rb\n", buf, 3))
		rot(stack_a, stack_b, 2, NULL);
	else if (ft_strlen(buf) == 3 && !ft_strncmp("rr\n", buf, 3))
		rot(stack_a, stack_b, 3, NULL);
	else if (ft_strlen(buf) == 4 && !ft_strncmp("rra\n", buf, 4))
		r_rot(stack_a, stack_b, 1, NULL);
	else if (ft_strlen(buf) == 4 && !ft_strncmp("rrb\n", buf, 4))
		r_rot(stack_a, stack_b, 2, NULL);
	else if (ft_strlen(buf) == 4 && !ft_strncmp("rrr\n", buf, 4))
		r_rot(stack_a, stack_b, 3, NULL);
	else
		return (0);
	return (1);
}

int	try_solve(t_stack *stack_a, t_stack *stack_b)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(0);
		if (!buf)
			return (1);
		if (!make_op(stack_a, stack_b, buf))
		{
			free(buf);
			return (0);
		}
		free(buf);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = create_stack();
	error_message(!stack_a);
	fill_args(argc, argv, stack_a);
	stack_b = create_stack();
	if (!stack_b)
		list_free(stack_a);
	error_message(!stack_b);
	if (!try_solve(stack_a, stack_b))
		write(2, "Error\n", 6);
	else if (!is_sorted(stack_a) || stack_b->len > 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	list_free(stack_a);
	list_free(stack_b);
	return (0);
}
