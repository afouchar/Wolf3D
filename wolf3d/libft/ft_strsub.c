/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:37:59 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/19 21:59:55 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*str;
	size_t	i;
	size_t	size;

	str = ft_strnew (n + 1);
	if (str == NULL)
		return (NULL);
	if (s == NULL || s[start] == '\0')
		return (NULL);
	size = ft_strlen(s);
	if (n + start > size)
		n = size - start;
	i = 0;
	while (i < n)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
