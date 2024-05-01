/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:51:36 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/25 16:28:25 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	clean_exit(t_stack *a, t_stack *b, int status)
{
	if (a)
	{
		a->prev->next = NULL;
		while (a->next)
		{
			a = a->next;
			free(a->prev);
		}
		free(a);
	}
	if (b)
	{
		b->prev->next = NULL;
		while (b->next)
		{
			b = b->next;
			free(b->prev);
		}
		free(b);
	}
	if (status == 1)
		write(2, "Error\n", 6);
	exit(status);
}

void	cleantab_exit(t_stack *a, char **tab, int status)
{
	int	i;

	i = 0;
	if (a)
	{
		a->prev->next = NULL;
		while (a->next)
		{
			a = a->next;
			free(a->prev);
		}
		free(a);
	}
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	if (status == 1)
		write(2, "Error\n", 6);
	exit(status);
}
