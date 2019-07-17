/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:08:16 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/17 17:52:51 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef				s_node
{
	int				data;
	struct s_node 	*next;
};

void	push(struct s_node **head, int new_data)
{
	s_node *new_node; 
	
	new_node = (s_node*)malloc(sizeof(s_node));
	new_node->data = new_data;
	new_node->data = (*head);
	(*head) = new_node;
}

void	put_after(struct s_node *p_node, int new_data)
{
	if (p_node == NULL)
	{
		printf("it is not null.");
		return;
	}

	s_node *new_node;
	new_node = (s_node*)malloc(size(s_node));
	new_node->data
}
