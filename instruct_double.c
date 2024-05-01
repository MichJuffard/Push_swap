/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:28:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/14 06:43:20 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	double_rotate(t_stack **a, t_stack **b)
{
	if (a || b || *a || *b)
	{
		*a = (*a)->next;
		*b = (*b)->next;
		ft_printf("rr\n");
	}
}

void	double_rev_rotate(t_stack **a, t_stack **b)
{
	if (a || b || *a || *b)
	{
		*a = (*a)->prev;
		*b = (*b)->prev;
		ft_printf("rrr\n");
	}
}
