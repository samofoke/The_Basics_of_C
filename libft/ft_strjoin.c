/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:39:30 by samofoke          #+#    #+#             */
/*   Updated: 2019/07/15 09:57:05 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	char	*pt;

	if (s1 && s2)
	{
		x = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (x)
		{
			pt = x;
			while (*s1)
				*pt++ = *s1++;
			while (*s2)
				*pt++ = *s2++;
			*pt = '\0';
			return (x);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
