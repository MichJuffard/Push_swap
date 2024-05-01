/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:24:08 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/15 02:29:09 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack *head)
{
	t_stack	*body;
	int		n;

	if (!head)
		return (0);
	n = head->content;
	body = head->next;
	while (body != head)
	{
		if (n >= body->content)
			return (0);
		n = body->content;
		body = body->next;
	}
	return (1);
}
