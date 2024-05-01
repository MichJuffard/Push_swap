/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:08:37 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/14 23:07:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_stack **from, t_stack **to, char c)
{
	t_stack	*temp;

	if (!from && !*from)
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
	ft_printf("p%c\n", c);
}

void	rev_rotate(t_stack **stack, char c)
{
	if (stack && *stack)
	{
		*stack = (*stack)->prev;
		ft_printf("rr%c\n", c);
	}
}

void	rotate(t_stack **stack, char c)
{
	if (stack && *stack)
	{
		*stack = (*stack)->next;
		ft_printf("r%c\n", c);
	}
}

void	swap(t_stack *stack, char c)
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
	ft_printf("s%c\n", c);
}
