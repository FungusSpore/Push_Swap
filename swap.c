/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:21:27 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/03 23:56:56 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s_ab(t_list **a)
{
	t_list *temp;

	if (ft_lstsize(*a) < 2)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}

void	sa(t_list **a)
{
	s_ab(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	s_ab(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	s_ab(a);
	s_ab(b);
	ft_printf("ss\n");
}
