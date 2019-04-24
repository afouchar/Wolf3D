/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 16:02:59 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/24 16:03:02 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst && new)
	{
		tmp = *alst;
		while (tmp)
		{
			if (tmp->next == NULL)
			{
				tmp->next = new;
				new->next = NULL;
			}
			tmp = tmp->next;
		}
	}
}
