/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:13 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/30 15:34:47 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <unistd.h>
#include <stdbool.h>


typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node *next;
	struct s_stack_node *prev;
	struct s_stack_node *top;
	struct s_stack_node *bottom;
}	t_stack_node;


/* Handle Errors */
int	error_and_free(t_stack_node **stack);
int	repeated(int nb, t_stack_node *stack);

/* Stack Creation  && errors*/
int	intitialize_stack_a(t_stack_node **stack, char **argv);
int	requisits_stack(char *array, t_stack_node **stack_ptr);
int	append_to_stack(int nb, t_stack_node **stack);

/*Utils*/
long	ps_atol(const char *str, unsigned int *error);
void	free_array(char **array);
t_stack_node *find_last_node(t_stack_node *stack);

/* ALgorithm */
int	push_swap(t_stack_node **a, t_stack_node **b);

/* Linked List utils */

/* Operations */
void	swap_elements(t_stack_node **stack);
void	swap_a(t_stack_node **stack_a);
void	swap_b(t_stack_node **stack_b);
void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	push_a(t_stack_node **a, t_stack_node **b);
void	push_b(t_stack_node **a, t_stack_node **b);
void	rotate(t_stack_node **stack);
void	rotate_a(t_stack_node **a);
void	rotate_b(t_stack_node **b);
void	rotate_both(t_stack_node **a, t_stack_node **b);
void	rev_rotate(t_stack_node **stack);
void	rev_rotate_a(t_stack_node **a);
void	rev_rotate_b(t_stack_node **b);
void	rev_rotate_both(t_stack_node **a, t_stack_node **b);

#endif
