/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:54:08 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:41:53 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*st;
	int		a;
	int		b;

	if (s1 != NULL && s2 != NULL)
	{
		a = ft_strlen(s1);
		b = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (a + b + 1));
		st = str;
		while (*s1 != '\0')
			*str++ = *s1++;
		while (*s2)
			*str++ = *s2++;
		*str = '\0';
		return (st);
	}
	else
		return (NULL);
}
