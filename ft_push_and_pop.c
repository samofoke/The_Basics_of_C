/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:33:34 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/17 15:35:16 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    struct node *next;
} Node;

int push( Node **stack, int val )
{
    Node *p = malloc( sizeof( Node ) );
    int success = p != NULL;

    if ( success )
    {
        p->v = val;
        p->next = *stack;
        *stack = p;
    }

    return success;
}

int pop( Node **stack, int *val )
{
    int success = *stack != NULL;

    if ( success )
    {
        Node *p = *stack;
        *stack = ( *stack )->next;
        *val = p->v;
        free( p );
    }       

    return success;
}

int main(void) 
{
    const int N = 10;
    Node *stack = NULL;

    int i = 0;
    int val;

    while ( i < N && push( &stack, i ) ) i++;

    while ( i != 0 && pop( &stack, &val ) ) printf( "%d ", val );

    printf( "\n" );

    return 0;
}
