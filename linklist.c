/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:15:32 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/17 17:52:34 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

struct	node
{
	int		data;
	struct	node *next;
};

void	linkedlist(struct node *n)
{
	while (n != NULL)
	{
		printf("%d\n",n->data);
		n = n->next;
	}
}

int		main(void)
{
	struct	node *head = NULL;
	struct	node *second = NULL;
	struct	node *third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	head->data = 2;
	head->next = third;

	head->data = 3;
	head->next = NULL;

	linkedlist(head);
	return (0);
}

