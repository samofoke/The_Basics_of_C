/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:59:10 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/15 09:50:31 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*x1;
	unsigned char	*x2;

	x1 = (unsigned char*)s1;
	x2 = (unsigned char*)s2;
	while (*x1 != '\0' || *x2 != '\0')
	{
		if (*x1 == *x2)
		{
			x1++;
			x2++;
		}
		else
			return (*x1 - *x2);
	}
	return (0);
}
