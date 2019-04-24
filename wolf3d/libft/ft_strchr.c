/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:14:33 by afouchar          #+#    #+#             */
/*   Updated: 2014/11/13 19:33:42 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return (&((char *)s)[i]);
			i++;
		}
		if ((char)c == '\0')
			return (&((char *)s)[i]);
	}
	return (0);
}
