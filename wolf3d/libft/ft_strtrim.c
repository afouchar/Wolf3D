/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:08:06 by afouchar          #+#    #+#             */
/*   Updated: 2014/11/16 15:04:11 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		len;
	char	*str;

	start = 0;
	len = 0;
	if (s != NULL)
	{
		while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
				&& (s[start] != 0))
			start++;
		str = ft_strdup(s + start);
		len = ft_strlen(str) - 1;
		while (len >= 0 && (str[len] == ' ' || str[len] == '\n' ||
				str[len] == '\t'))
			len--;
		str[len + 1] = '\0';
		return (str);
	}
	return (NULL);
}
