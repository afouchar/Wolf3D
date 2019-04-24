/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 18:27:54 by afouchar          #+#    #+#             */
/*   Updated: 2015/01/21 20:56:40 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	if (lst && *f)
	{
		new = f(lst);
		tmp = new;
		lst = lst->next;
		while (lst != NULL)
		{
			tmp->next = f(lst);
			tmp = tmp->next;
			lst = lst->next;
		}
		tmp->next = NULL;
		return (new);
	}
	return (NULL);
}
