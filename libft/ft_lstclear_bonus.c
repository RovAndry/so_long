/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:45:19 by randrina          #+#    #+#             */
/*   Updated: 2024/02/28 14:37:52 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst;
	if (tmp1 != NULL)
	{
		while (tmp1->next)
		{
			tmp2 = tmp1->next;
			del(tmp1->content);
			free(tmp1);
			tmp1 = tmp2;
		}
		del(tmp1->content);
		free(tmp1);
		*lst = NULL;
	}
}
