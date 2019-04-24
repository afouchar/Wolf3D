/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:35:41 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:58:53 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			t;
	int			a;
	int			b;

	t = 0;
	a = 0;
	b = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	while (s[a] != '\0')
	{
		b = a;
		if (s[a] == c && s[a] != '\0')
			a++;
		else
		{
			while ((s[a] != c) && (s[a] != '\0'))
				a++;
			tab[t++] = ft_strsub(s, b, (a - b));
		}
	}
	tab[t] = NULL;
	return (tab);
}
