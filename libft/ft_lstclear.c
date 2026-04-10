/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svpanfil <svpanfil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 12:07:17 by svpanfil      #+#    #+#                 */
/*   Updated: 2026/03/17 12:07:18 by svpanfil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (*lst && del)
	{
		while (*lst)
		{
			node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = node;
		}
	}
}
