/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:16:41 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 17:32:55 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_stack_node *a, int *array, size_t len);

void	set_rank(t_stack_node *a, size_t len)
{
	int		*array;
	size_t	i;
	// t_stack_node *tmp;

	array = (int *)malloc(sizeof(int) * (len));
	if (!array)
		return ;
	i = 0;
	// tmp = a;
	while (a)
	{
		array[i] = a->value;
		a = a->next;
		i++;
	}
	sort_array(array, len);
	assign_ranks(a, array, len);
	free(array);
}

static void	assign_ranks(t_stack_node *a, int *array, size_t len)
{
	size_t	i;

	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (a->value == array[i])
			{
				a->rank = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

int	define_chunk_size(int len)
{
	if (len <= 10)
		return (1);
	else if (len <= 100)
		return (5);
	else
		return (11);
}

void	set_chunk(t_stack_node *a, int len, int chunks)
{
	int	base;
	int	extra;
	int	rank;

	base = len / chunks;
	extra = len % chunks;
	while (a)
	{
		rank = a->rank;
		if (rank < (base + 1) * extra)
			a->chunk = (rank / (base + 1)) + 1;
		else
			a->chunk = ((rank - ((base + 1) * extra)) / base) + extra + 1;
		a = a->next;
	}
}
