/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:40:13 by afretta-          #+#    #+#             */
/*   Updated: 2026/01/19 15:28:12 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					rank;
	int					cost;
	int					chunk;
	bool				allowed;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;

}						t_stack_node;

/* Handle Errors & Initialize Stack */
void					error_and_free(t_stack_node **stack);
void					free_array(char **array);
int						intitialize_stack_a(t_stack_node **stack, char **argv);

/*Utils*/
long					ps_atol(const char *str, unsigned int *error);
bool					is_repeated(int nb, t_stack_node *stack);
bool					is_sorted(t_stack_node *a);
size_t					stack_len(t_stack_node *stack);
void					sort_array(char array, size_t len);

/*Find in Stack*/
t_stack_node			*find_last_node(t_stack_node *stack);
t_stack_node			*find_highest(t_stack_node *stack);
t_stack_node			*find_lowest(t_stack_node *stack);
t_stack_node			*find_cheapest(t_stack_node *stack);
//find_highest_rank();

/*Set in Stack*/
void					set_rank(t_stack_node *a, size_t len);
void					set_current_position(t_stack_node *stack);
void					set_target_node(t_stack_node *src, t_stack_node *dst,
							char src_stack);
void					set_b_target_node(t_stack_node *a, t_stack_node *b);
void					set_a_target_node(t_stack_node *a, t_stack_node *b);

/*Cost Caltulations*/
void					set_cost_move(t_stack_node *stack);
void					set_cheapest_move(t_stack_node *stack);

/* Push Swap Algorithm */
void					sort_stack(t_stack_node **a, t_stack_node **b);

/*Tiny sort*/
void					sort_three(t_stack_node **a);
void					sort_until_five(t_stack_node **a, t_stack_node **b);

/*Algorithm rotations*/
void					special_rotate(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					special_rev_rotate(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					final_rotations(t_stack_node **stack, t_stack_node *expected);

/*Final Sort*/
void					final_sort_asc(t_stack_node **a);

/* Operations */
void					swap_elements(t_stack_node **stack);
void					swap_a(t_stack_node **stack_a);
void					swap_b(t_stack_node **stack_b);
void					swap_ss(t_stack_node **stack_a, t_stack_node **stack_b);
void					push_a(t_stack_node **a, t_stack_node **b);
void					push_b(t_stack_node **a, t_stack_node **b);
void					rotate(t_stack_node **stack);
void					rotate_a(t_stack_node **a);
void					rotate_b(t_stack_node **b);
void					rotate_both(t_stack_node **a, t_stack_node **b);
void					rev_rotate(t_stack_node **stack);
void					rev_rotate_a(t_stack_node **a);
void					rev_rotate_b(t_stack_node **b);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b);

#endif
