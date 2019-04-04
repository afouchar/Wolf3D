/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:15:40 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/19 20:23:30 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	if (s2[0] == '\0' && s1 != NULL)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			l = i;
			while (s2[j] == s1[l++] && s2[j] != '\0')
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
