/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afretta- <afretta-@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:01:49 by afretta-          #+#    #+#             */
/*   Updated: 2025/12/17 10:42:57 by afretta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int	x; //value || element
	struct Node *next; //pointer in the same building block
} Node;

void insert_end(Node **root, int value)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
		exit (1);//return 1 on the main function
	new_node->next = NULL;
	new_node->x = value;

	Node *curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

int	main(void)
{
	Node *root = malloc(sizeof(Node));
	if (!root)
		return(1);
	root->x = 15;
	root->next = NULL;

	insert_end(&root, -2);
	insert_end(&root, -11);

	Node *curr = root;
	while(curr)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	return (0);
}

