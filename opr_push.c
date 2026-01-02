/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:34:02 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/29 16:26:28 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_a;

	if (!b || !(*b))
		return ;
	first_a = (*b);
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	first_a->prev = NULL;
	first_a->next = *a;
	if (*a)
		(*a)->prev = first_a;
	*a = first_a;
	write(1, "pa\n", 3);
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_b;

	if (!a || !(*a))
		return ;
	first_b = (*a);
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	first_b->prev = NULL;
	first_b->next = *b;
	if (*b)
		(*b)->prev = first_b;
	*b = first_b;
	write(1, "pb\n", 3);
}
