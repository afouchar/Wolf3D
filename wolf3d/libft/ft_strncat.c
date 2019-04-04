/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:21:59 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:50:31 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t i)
{
	char *str;

	if (s1 != NULL && s2 != NULL)
	{
		str = s1;
		while (*s1 != '\0')
			s1++;
		while (i > 0)
		{
			*s1++ = *s2++;
			i--;
		}
		*s1 = '\0';
		return (str);
	}
	else
		return (NULL);
}
