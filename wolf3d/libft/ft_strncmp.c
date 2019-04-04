/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:22:06 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/19 19:09:44 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while ((*s1 || *s2) && (n > 0))
		{
			if (*s1 != *s2)
				return (((unsigned char)*s1) - ((unsigned char)*s2));
			n--;
			s1++;
			s2++;
		}
	}
	return (0);
}
