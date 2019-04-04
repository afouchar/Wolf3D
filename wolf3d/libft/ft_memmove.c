/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:05:35 by afouchar          #+#    #+#             */
/*   Updated: 2014/11/15 17:42:00 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		str[j] = ((char *)src)[j];
		j++;
	}
	while (i < len)
	{
		((char *)dest)[i] = str[i];
		i++;
	}
	free(str);
	return ((char *)dest);
}
