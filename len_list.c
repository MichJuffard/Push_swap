/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:03:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/14 05:09:34 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	len_list(t_stack *head)
{
	size_t	len;
	t_stack	*body;

	if (!head)
		return (0);
	body = head->next;
	len = 1;
	while (body != head)
	{
		len++;
		body = body->next;
	}
	return (len);
}
