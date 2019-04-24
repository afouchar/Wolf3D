/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:26:16 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:42:09 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	t1;
	unsigned int	t2;
	int				len;

	if (dest != NULL && src != NULL)
	{
		t1 = ft_strlen(dest);
		t2 = ft_strlen(src);
		len = size - t1 - 1;
		if (size <= t1)
			return (size + t2);
		while (*dest != '\0')
			dest++;
		while ((*src != '\0') && (len > 0))
		{
			*dest++ = *src++;
			len--;
		}
		*dest = '\0';
		return (t1 + t2);
	}
	else
		return (0);
}
