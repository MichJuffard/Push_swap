/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:55:34 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/25 16:28:44 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>

typedef struct s_stack
{
	int				content;
	size_t			final_i;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	rotate(t_stack **stack, char c);
void	rev_rotate(t_stack **stack, char c);
void	push(t_stack **from, t_stack **to, char c);
void	swap(t_stack *stack, char c);
int		check_double(t_stack *head);
t_stack	*create_stack(char **arg, int size);
void	add_new_elem(t_stack **stack, t_stack *new);
int		check_arg(char *arg);
void	final_index(t_stack *head);
void	clean_exit(t_stack *a, t_stack *b, int status);
void	cleantab_exit(t_stack *a, char **tab, int status);
int		check_order(t_stack *head);
size_t	found_bigger(t_stack *head);
void	double_rev_rotate(t_stack **a, t_stack **b);
void	double_rotate(t_stack **a, t_stack **b);
size_t	len_list(t_stack *head);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_3_left(t_stack **a);
void	korean_presort(t_stack **a, t_stack **b);

#endif