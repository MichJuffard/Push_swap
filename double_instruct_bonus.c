/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instruct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:02:24 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/15 02:05:52 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	double_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	double_rev_rotate(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
