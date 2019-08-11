/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tras_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:27:09 by samofoke          #+#    #+#             */
/*   Updated: 2019/08/05 16:57:09 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

void	push_node(t_node **p_head, int data)
{
	t_node *pt1;
	t_node *tmp;

	pt1 = (t_node*)malloc(sizeof(t_node));
	tmp = *p_head;
	pt1->data = data;
	pt1->next = NULL;

	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = pt1;
	}
	else
		*p_head = pt1;
}

void	printlist(t_node *all_head)
{
	t_node *tmp;

	tmp = all_head;
	while (tmp)
	{
		printf(" %d ", tmp->data);
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_node *head;
	
	head = NULL;
	push_node(&head, 1);
	push_node(&head, 2);
	push_node(&head, 3);
	push_node(&head, 4);
	push_node(&head, 5);
	printf("the contents are: ");
	printlist(head);
	return (0);
}
