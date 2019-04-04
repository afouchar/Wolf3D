/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:00:54 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:42:59 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s2[i] && (n > 0))
		{
			s1[i] = s2[i];
			n--;
			i++;
		}
		while (n > 0)
		{
			s1[i] = '\0';
			n--;
			i++;
		}
		return (s1);
	}
	else
		return (NULL);
}
