/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:11:28 by randrina          #+#    #+#             */
/*   Updated: 2024/02/28 14:35:30 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new;
	t_list	*nw;
	void	*content;

	new = (t_list **)malloc(sizeof(t_list *));
	if (new == NULL)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		nw = ft_lstnew(content);
		del(nw->content);
		ft_lstadd_back(new, nw);
		lst = lst->next;
	}
	return (*new);
}
