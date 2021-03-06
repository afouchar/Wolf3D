/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:49:16 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:40:15 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s2 != NULL)
	{
		while (s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	else
		return (NULL);
}
