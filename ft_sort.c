/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:07:04 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/14 07:17:10 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	korean_presort(t_stack **a, t_stack **b)
{
	int		y;
	size_t	i;
	size_t	len;

	i = 0;
	len = len_list(*a);
	y = (0.000000053 * len * len) + (0.03 * len) + 14.5;
	while (len_list(*a) > 3)
	{
		if ((*a)->final_i < i && (*a)->final_i < len - 3)
			push(a, b, 'b');
		else if ((*a)->final_i < i + y && (*a)->final_i < len - 3)
		{
			push(a, b, 'b');
			if ((*a)->final_i > i + y && (*a)->final_i < len - 3)
				double_rotate(a, b);
			else if (*b != (*b)->next)
				rotate(b, 'b');
		}
		else
			rotate(a, 'a');
		if ((*a)->final_i < i + y && (*a)->final_i < len - 3)
			i++;
	}
}

static void	push_lower(t_stack **a, t_stack **b, size_t index)
{
	index = len_list(*b) - index;
	while (index > 0)
	{
		if ((*a)->prev->final_i == len_list(*a) + len_list(*b) - 1)
		{
			push(b, a, 'a');
			rotate(a, 'a');
		}
		if ((*b)->final_i > (*a)->prev->final_i && \
			(*b)->final_i != (*a)->final_i - 1)
		{
			push(b, a, 'a');
			rotate(a, 'a');
		}
		if ((*a)->prev->final_i == (*a)->final_i - 1)
			double_rev_rotate(a, b);
		else
			rev_rotate(b, 'b');
		index--;
	}
	if ((*b)->final_i == (*a)->final_i - 1)
		push(b, a, 'a');
}

static void	push_upper(t_stack **a, t_stack **b, size_t index)
{
	while (index > 0)
	{
		if ((*a)->prev->final_i == len_list(*a) + len_list(*b) - 1)
		{
			push(b, a, 'a');
			double_rotate(a, b);
		}
		else if ((*b)->final_i > (*a)->prev->final_i && \
			(*b)->final_i != (*a)->final_i - 1)
		{
			push(b, a, 'a');
			double_rotate(a, b);
		}
		else if ((*a)->prev->final_i == (*a)->final_i - 1)
			rev_rotate(a, 'a');
		else
			rotate(b, 'b');
		index--;
	}
	if ((*b)->final_i == (*a)->final_i - 1)
		push(b, a, 'a');
}

void	sort_stack(t_stack **a, t_stack **b)
{
	size_t	bigger_i;

	while (*b)
	{
		bigger_i = found_bigger(*b);
		if ((*a)->prev->final_i == (*a)->final_i - 1)
			rev_rotate(a, 'a');
		if (bigger_i > len_list(*b) / 2)
			push_lower(a, b, bigger_i);
		else
			push_upper(a, b, bigger_i);
	}
	while (!check_order(*a))
		rev_rotate(a, 'a');
}

void	sort_3_left(t_stack **a)
{
	if ((*a)->final_i < (*a)->next->final_i && (*a)->final_i < \
		(*a)->prev->final_i && (*a)->next->final_i > (*a)->prev->final_i)
	{
		swap(*a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->final_i > (*a)->next->final_i && (*a)->final_i < \
		(*a)->prev->final_i && (*a)->next->final_i < (*a)->prev->final_i)
		swap(*a, 'a');
	else if ((*a)->final_i < (*a)->next->final_i && (*a)->final_i > \
		(*a)->prev->final_i && (*a)->next->final_i > (*a)->prev->final_i)
		rev_rotate(a, 'a');
	else if ((*a)->final_i > (*a)->next->final_i && (*a)->final_i > \
		(*a)->prev->final_i && (*a)->next->final_i > (*a)->prev->final_i)
	{
		swap(*a, 'a');
		rev_rotate(a, 'a');
	}
	else if ((*a)->final_i > (*a)->next->final_i && (*a)->final_i > \
		(*a)->prev->final_i && (*a)->next->final_i <= (*a)->prev->final_i)
		rotate(a, 'a');
}
