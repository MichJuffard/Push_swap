/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_biger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:07:33 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/14 05:08:51 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	found_bigger(t_stack *head)
{
	size_t	bigger;
	size_t	ret;
	t_stack	*body;

	bigger = head->final_i;
	ret = 0;
	body = head->next;
	while (body != head)
	{
		if (body->final_i > bigger)
			bigger = body->final_i;
		body = body->next;
	}
	while (body->final_i != bigger)
	{
		ret++;
		body = body->next;
	}
	return (ret);
}
