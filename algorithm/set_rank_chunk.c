/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:16:41 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/21 15:00:32 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_stack_node *a, int *array, size_t len);

void	set_rank(t_stack_node *a, size_t len)
{
	int		*array;
	size_t	i;

	array = (int *)malloc(sizeof(int) * (len));
	if (!array)
		return ;
	i = 0;
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
	int	nodes_per_chunk;
	int	assigned_chunk;

	nodes_per_chunk = len / chunks;
	while (a)
	{
		assigned_chunk = (a->rank / nodes_per_chunk) + 1;
		if (assigned_chunk > chunks)
			assigned_chunk = chunks;
		a->chunk = assigned_chunk;
		a = a->next;
	}
}
