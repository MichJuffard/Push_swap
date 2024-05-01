/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:16:38 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 05:22:03 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = create_stack(argv, argc - 1);
	if (!a)
	{
		write(2, "Fail to create stack\n", 21);
		clean_exit(a, b, 1);
	}
	if (!a)
		return (0);
	final_index(a);
	if (!check_double(a))
		clean_exit(a, b, 1);
	if (!check_order(a))
	{
		korean_presort(&a, &b);
		sort_3_left(&a);
		sort_stack(&a, &b);
	}
	clean_exit(a, b, 0);
}
