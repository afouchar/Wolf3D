/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:25:10 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:42:45 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		str = (char*)malloc(sizeof(char) * (len + 1));
		len = 0;
		while (s[len] != '\0')
		{
			str[len] = (*f)(len, s[len]);
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	else
		return (NULL);
}
