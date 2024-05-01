/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:35:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/15 03:35:44 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "errno.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static void	use_instruct(t_stack **a, t_stack **b, char *instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		return (push(b, a));
	if (!ft_strcmp(instruction, "pb\n"))
		return (push(a, b));
	if (!ft_strcmp(instruction, "sa\n"))
		return (swap(*a));
	if (!ft_strcmp(instruction, "sb\n"))
		return (swap(*b));
	if (!ft_strcmp(instruction, "ss\n"))
		return (double_swap(*a, *b));
	if (!ft_strcmp(instruction, "ra\n"))
		return (rotate(a));
	if (!ft_strcmp(instruction, "rb\n"))
		return (rotate(b));
	if (!ft_strcmp(instruction, "rr\n"))
		return (double_rotate(a, b));
	if (!ft_strcmp(instruction, "rra\n"))
		return (rev_rotate(a));
	if (!ft_strcmp(instruction, "rrb\n"))
		return (rev_rotate(b));
	if (!ft_strcmp(instruction, "rrr\n"))
		return (double_rev_rotate(a, b));
	free(instruction);
	clean_exit(*a, *b, 1);
}

static void	read_instruct(t_stack **a, t_stack **b, char *line)
{
	while (line)
	{
		use_instruct(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc <= 1)
		return (0);
	a = create_stack(argv, argc - 1);
	final_index(a);
	if (!a || !check_double(a))
		clean_exit(a, b, 1);
	read_instruct(&a, &b, get_next_line(0));
	if (errno)
		clean_exit(a, b, 1);
	if (!check_order(a) || b != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	clean_exit(a, b, 0);
}
