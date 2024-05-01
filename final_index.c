/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/15 01:50:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_index(t_stack *head)
{
	t_stack	*body;
	t_stack	*foot;

	if (!head)
		return ;
	foot = head->prev;
	while (head)
	{
		body = head->next;
		while (body != head)
		{
			if (head->content > body->content)
				head->final_i++;
			body = body->next;
		}
		if (head == foot)
			break ;
		head = head->next;
	}
}
