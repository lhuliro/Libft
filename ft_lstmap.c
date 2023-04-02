/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:54:43 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/03/31 17:28:43 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_sub;
	t_list	*node;

	if (!f || !del || lst == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	lst_sub = lst->next;
	while (lst_sub)
	{
		node = ft_lstnew(f(lst_sub->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst_sub = lst_sub->next;
	}
	return (new_lst);
}

// t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
//     t_list  *newlist;
//     t_list  *p;
//     t_list  *elem;
//     if (!lst || !f || !del)
//         return (NULL);
//     newlist = ft_lstnew((*f)(lst->content));
//     if (!newlist)
//         return (NULL);
//     p = lst->next;
//     while (p)
//     {
//         elem = ft_lstnew((*f)(p->content));
//         if (!elem)
//         {
//             ft_lstclear(&newlist, del);
//             return (NULL);
//         }
//         ft_lstadd_back(&newlist, elem);
//         p = p->next;
//     }
//     return (newlist);
// }
