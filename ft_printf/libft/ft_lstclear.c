/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:03:06 by senam             #+#    #+#             */
/*   Updated: 2021/05/13 13:27:52 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lst_ptr;

	lst_ptr = (*lst);
	while (lst_ptr)
	{
		tmp = lst_ptr;
		lst_ptr = lst_ptr->next;
		(del)(tmp->content);
		free(tmp);
	}
	*lst = 0;
}
