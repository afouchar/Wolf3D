/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:26:09 by afouchar          #+#    #+#             */
/*   Updated: 2014/11/15 18:01:40 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	if (s != NULL)
	{
		n = ft_strlen((char *)s);
		while (n >= 0)
		{
			if (s[n] == (char)c)
				return (&((char *)s)[n]);
			n--;
		}
		if ((char)c == '\0')
			return (&((char *)s)[n]);
	}
	return (0);
}
