/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:01:59 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:38:30 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (*del)
			(*del)((*alst)->content, (*alst)->content_size);
		else
			free((*alst)->content);
		(*alst)->content = NULL;
		ft_memdel((void**)alst);
	}
}
