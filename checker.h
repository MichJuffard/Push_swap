/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:58:08 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/15 02:06:40 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stddef.h>

typedef struct s_stack
{
	int				content;
	size_t			final_i;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		check_order(t_stack *head);
t_stack	*create_stack(char **arg, int size);
void	clean_exit(t_stack *a, t_stack *b, int status);
void	swap(t_stack *stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	add_new_elem(t_stack **stack, t_stack *new);
int		check_double(t_stack *head);
void	final_index(t_stack *head);
void	double_rev_rotate(t_stack **a, t_stack **b);
void	double_rotate(t_stack **a, t_stack **b);
void	double_swap(t_stack *a, t_stack *b);

#endif