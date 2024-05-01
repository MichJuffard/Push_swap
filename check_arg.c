/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:49:37 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/14 06:42:51 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_arg(char *arg)
{
	size_t	i;

	i = 1;
	if (!(ft_isdigit(arg[0]) || ((arg[0] == '+' || arg[0] == '-') && \
			ft_isdigit(arg[1])) || arg[0] == ' '))
		return (0);
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i]) || ((arg[i] == '+' || arg[i] == '-') && \
			ft_isdigit(arg[i + 1]) && arg[i - 1] == ' ') || arg[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(t_stack *head)
{
	t_stack	*body;
	t_stack	*foot;

	foot = head->prev;
	while (1)
	{
		body = head->next;
		while (body != foot)
		{
			if (body->content == head->content)
				return (0);
			body = body->next;
		}
		if (head == foot)
			break ;
		head = head->next;
	}
	return (1);
}
