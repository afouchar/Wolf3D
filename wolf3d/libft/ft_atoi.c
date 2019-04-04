/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:56:54 by afouchar          #+#    #+#             */
/*   Updated: 2014/11/15 15:35:15 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int value;
	int isneg;

	isneg = 1;
	value = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') || (*str == '\v')
	|| (*str == '\r') || (*str == '\f'))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			isneg = -1;
		str++;
	}
	while ((*str >= 48) && (*str <= 57))
	{
		value = (value * 10) + (*str - 48);
		str++;
	}
	return ((isneg * value));
}
