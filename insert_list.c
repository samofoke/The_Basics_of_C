/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 04:37:16 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/23 21:38:34 by slimy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct			s_node
{
	int				data;
	struct	s_node 	*next;
	struct	s_node	*prev;
}				t_node;

//adding a new node infront of the list.
void	push_new(t_node **head_rf, int new_data)
{
	t_node *new_node;

	new_node = (t_node*)malloc(sizeof(t_node));
	new_node->data = new_data;
	new_node->next = (*head_rf);
	new_node->prev = NULL;

	if ((*head_rf) != NULL)
		(*head_rf)->prev = new_node;
	(*head_rf) = new_node;
}

//this functions adds a node after the prev node.
void	add_after(t_node *p_node, int new_data)
{
	t_node *new_node;

	if (p_node == NULL)
	{
		printf("the prev node cannot be null.\n\n");
		return ;
	}
	new_node = (struct s_node*)malloc(sizeof(struct s_node));

	new_node->data = new_data;
	new_node->next = p_node->next;
	p_node->next = new_node;
	new_node->prev = p_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

//this function appends a new node to the end.
void	append(t_node **head_rf, int new_data)
{
	t_node *new_node;

	new_node = (t_node*)malloc(sizeof(t_node));

	t_node *last = *head_rf;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_rf == NULL)
	{
		new_node->prev = NULL;
		*head_rf = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return ;
}

//printing the linked list from the given note.
void	print_list(t_node *node)
{
	t_node *last;

	printf("forward direction.\n");
	while (node != NULL)
	{
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
	printf("\nreverse direction.\n");
	while (last != NULL)
	{
		printf(" %d ",last->data);
		last = last->prev;
	}
}

int		main(void)
{
	t_node *head = NULL;

	//append(&head, 6);
	push_new(&head, 7);
	//push_new(&head, 1);
	append(&head, 4);
	add_after(head->next, 8);
	printf("added a list: \n");
	print_list(head);
	//getchar();
	printf("\n");
	return (0);
}
