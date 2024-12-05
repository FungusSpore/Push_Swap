/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:32:48 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/07 22:55:19 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		del((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
// void	del(void *ptr)
// {
// 	free(ptr);
// }
//
// #include <stdio.h>
// int main(void)
// {
// 	t_list	*temp;
// 	t_list	*lst;
//
// 	int *data = malloc(sizeof(int));
// 	*data = 69;
// 	t_list *head = ft_lstnew(data);
// 	int *data2 = malloc(sizeof(int));
// 	*data2 = 420;
// 	int *data3 = malloc(sizeof(int));
// 	*data3 = 42;
// 	ft_lstadd_back(&head, ft_lstnew(data2));
// 	ft_lstadd_back(&head, ft_lstnew(data3));
// 	printf("%d\n", ft_lstsize(head));
// 	ft_lstclear(&head, del);
// 	printf("%d\n", ft_lstsize(head));
// 	return(0);
// }