/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:13 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/16 17:07:23 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node *next;
	struct s_stack_noce *prev;
}	t_stack_node;


/* Handle Errors */

/* Stack Creation  && errors*/
void	intitialize_stack_a(t_stack_node **a, char **argv);

/* ALgorithm */

/* Linked List utils */

/* Commands */
// sa(swap a)
// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
// sb(swap b)
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
// ss(sa and sb at the same time)
// pa(push a)
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb(push b)
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra(rotate a)
// Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb(rotate b)
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr(ra and rb at the same time)
// rra(reverse rotate a)
// Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb(reverse rotate b)
// Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr()
//rra and rrb at the same time.

#endif
