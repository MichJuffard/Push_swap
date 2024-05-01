/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:39:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/25 16:29:49 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_stack	*new_elem(int content)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack) * 1);
	if (!new_elem)
		return (0);
	new_elem->content = content;
	new_elem->final_i = 0;
	new_elem->next = new_elem;
	new_elem->prev = new_elem;
	return (new_elem);
}

static int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	add_new_elem(t_stack **stack, t_stack *new)
{
	if (!*stack)
		*stack = new;
	else
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		*stack = new;
		(*stack)->prev->next = *stack;
		(*stack)->next->prev = *stack;
	}
}

static int	create_number(char *arg, t_stack *stack, char **tab)
{
	size_t	i;
	int		sign;
	long	ret;

	i = 0;
	ret = 0;
	sign = 1;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i])
	{
		if (ret > INT_MAX / 10)
			cleantab_exit(stack, tab, 1);
		ret = ret * 10;
		if ((-ret < INT_MIN + (arg[i] - '0') && sign == -1) || \
			(ret > INT_MAX - (arg[i] - '0') && sign == 1))
			cleantab_exit(stack, tab, 1);
		ret = ret + arg[i] - '0';
		i++;
	}
	return (ret * sign);
}

t_stack	*create_stack(char **arg, int size)
{
	t_stack	*stack;
	char	**tab;
	int		i;

	stack = NULL;
	while (size > 0)
	{
		if (!check_arg(arg[size]))
			clean_exit(stack, NULL, 1);
		tab = ft_split(arg[size], ' ');
		i = tab_len(tab);
		while (i-- > 0)
		{
			add_new_elem(&stack, new_elem(create_number(tab[i], stack, tab)));
			free(tab[i]);
		}
		free(tab);
		size--;
	}
	return (stack);
}
