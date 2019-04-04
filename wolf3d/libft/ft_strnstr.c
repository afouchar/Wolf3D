/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:34:13 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/19 21:44:31 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*c1;
	char	*c2;
	int		len;
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	c1 = (char *)s1;
	c2 = (char *)s2;
	len = ft_strlen(c2);
	i = 0;
	while (c1[i] && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return (c1 + i);
		i++;
	}
	return (NULL);
}
