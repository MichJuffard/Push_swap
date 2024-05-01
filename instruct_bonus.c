/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:08:37 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/15 00:30:14 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	(*from)->next->prev = (*from)->prev;
	(*from)->prev->next = (*from)->next;
	if (*from == (*from)->next)
		*from = NULL;
	else
		*from = (*from)->next;
	if (!*to)
	{
		*to = temp;
		(*to)->next = *to;
		(*to)->prev = *to;
	}
	else
		add_new_elem(to, temp);
}

void	rev_rotate(t_stack **stack)
{
	if (stack && *stack)
		*stack = (*stack)->prev;
}

void	rotate(t_stack **stack)
{
	if (stack && *stack)
		*stack = (*stack)->next;
}

void	swap(t_stack *stack)
{
	t_stack	temp;

	if (!stack)
		return ;
	temp.content = stack->content;
	temp.final_i = stack->final_i;
	stack->content = stack->next->content;
	stack->final_i = stack->next->final_i;
	stack->next->content = temp.content;
	stack->next->final_i = temp.final_i;
}
