/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:16:41 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/09 15:25:03 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void assign_ranks(t_stack_node *a, int *array, size_t len);

void	set_rank(t_stack_node *a, size_t len)
{
	int *array;
	size_t i;

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
	assign_rank(a, array, len);
	free_array(array);
}

static void assign_ranks(t_stack_node *a, int *array, size_t len)
{
	size_t	i;
	while (a)
	{
		i = 0;
		while(i < len)
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
	int	chunk_size;

	if (len <=10)
		chunk_size = len / 1;
	if (len <= 100)
		chunk_size = len / 5;
	else
		chunk_size = len / 11;
}

void	set_chunk(t_stack_node *a, int len, int	chunk_size)
{
	int				nodes_per_chunk;
	int				chunk;
	t_stack_node 	*current;

	nodes_per_chunk = len / chunk_size;
	while(current)
	{
		chunk = (current->rank / nodes_per_chunk) + 1;
		if (chunk > chunk_size)
			chunk = chunk_size;
		current->chunk = chunk;
		current = current->next;
	}
}

