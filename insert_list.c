/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 04:37:16 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/22 18:43:41 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

struct				s_node
{
	int				data;
	struct	s_node 	*next;
	struct	s_node	*prev;
};

//adding a new node infront of the list.
void	push_new(struct s_node **h_one, int new_data)
{
	struct s_node *new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));
	new_node->data = new_data;
	new_node->next = (*h_one);
	new_node->prev = NULL;

	if ((*h_one) != NULL)
		(*h_one)->prev = new_node;
	(*h_one) = new_node;
}

void	add_after(struct s_node *p_node, int new_data)
{
	struct s_node *new_node;

	if (p_node == NULL)
	{
		printf("the prev node cannot be null.\n\n");
		return ;
	}

	new_node->data = new_data;
	new_node->next = p_node->next;
	p_node->next = new_node;
	new_node->prev = p_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

//this function appends a new node to the end.
void	append(struct s_node *head_rf, int new_data)
{
	struct s_node *new_node;

	new_node = (struct s_node*)malloc(sizeof(struct s_node));

	struct s_node *last = head_rf;

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
void	print_list(struct s_node *node)
{
	struct s_node *last;

	printf("forward direction.\n");
	while (node != NULL)
	{
		printf("%d\n", node->data);
		last = node;
		node = node->next;
	}
	printf("reverse direction.\n");
	while (last != NULL)
	{
		printf("%d\n",last->data);
		last = last->prev;
	}
}

int		main(void)
{
	struct s_node *head = NULL;

	push_new(&head, 3);
	add_after(head->next, 4);
	printf("added a list: \n\n");
	print_list(head);
	//getchar();
	return (0);
}
