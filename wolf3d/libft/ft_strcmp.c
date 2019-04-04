/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:30:12 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/19 19:08:15 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 == *s2++)
		{
			if (*s1++ == '\0')
				return (0);
		}
		return (((unsigned char)*s1) - ((unsigned char)*(s2 - 1)));
	}
	return (0);
}
