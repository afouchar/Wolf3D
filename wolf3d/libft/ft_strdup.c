/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:34:57 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:41:24 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*st;
	int		len;

	if (src != NULL)
	{
		len = ft_strlen(src);
		str = (char *)malloc(sizeof(str) * (len + 1));
		st = str;
		while (*src)
			*str++ = *src++;
		*str = '\0';
		return (st);
	}
	else
		return (NULL);
}
