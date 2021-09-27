/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:58:10 by senam             #+#    #+#             */
/*   Updated: 2021/05/13 13:27:11 by senam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_ptr;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	lst_ptr = (*lst);
	while (lst_ptr->next)
		lst_ptr = lst_ptr->next;
	lst_ptr->next = new;
}
