/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:12:54 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/20 19:27:39 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*t_node;

	map = NULL;
	while (lst)
	{
		t_node = ft_lstnew(f(lst->content));
		if (!t_node)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		if (!map)
			map = t_node;
		else
			ft_lstadd_back(&map, t_node);
		lst = lst->next;
	}
	return (map);
}
