/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:42:25 by afouchar          #+#    #+#             */
/*   Updated: 2014/11/16 15:05:06 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				tmp;
	int				isneg;
	unsigned int	usi;

	i = 0;
	tmp = n;
	isneg = 0;
	usi = n;
	while ((tmp /= 10) != 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (n < 0 && i++)
	{
		isneg = 1;
		usi = -n;
	}
	str[i + 1] = '\0';
	while (i >= 0 && (str[i--] = (usi % 10) + '0'))
		usi /= 10;
	if (isneg == 1)
		str[0] = '-';
	return (str);
}
