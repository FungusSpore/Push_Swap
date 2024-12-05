/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:11:00 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/05 15:48:21 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// to optimize sorting 3 elements
static void	sort_three(t_list **a)
{
	int	top_g_mid;
	int mid_g_bot;
	int	bot_g_top;

	// printf("before: %d\n",((t_data *)(*a)->content)->data);
	top_g_mid = ((t_data *)(*a)->content)->data > ((t_data *)(*a)->next->content)->data;
	mid_g_bot = ((t_data *)(*a)->next->content)->data > ((t_data *)(*a)->next->next->content)->data;
	bot_g_top = ((t_data *)(*a)->next->next->content)->data > ((t_data *)(*a)->content)->data;
	if (!top_g_mid && mid_g_bot && bot_g_top)
	{
		sa(a);
		ra(a);
	}
	if (top_g_mid && !mid_g_bot && bot_g_top)
		sa(a);
	if (!top_g_mid && mid_g_bot && !bot_g_top)
		rra(a);
	if (top_g_mid && !mid_g_bot && !bot_g_top)
		ra(a);
	if (top_g_mid && mid_g_bot && !bot_g_top)
	{
		sa(a);
		rra(a);
	}
	// printf("after: %d\n",((t_data *)(*a)->content)->data);
}

static void	insert_position(t_list **a, t_list **b)
{
	int		insert;
	int		i;
	int		j;
	t_list	*current;

	insert = ((t_data *)(*b)->content)->data;
	i = 0;
	j = 0;
	current = *a;
	// printf("insert: %d", insert);
	// printf("b: %d", ((t_data *)current->content)->data);
	while (current)
	{
		if (((t_data *)current->content)->data > insert)
			break ;
		current = current->next;
		i++;
	}
	if (i == ft_lstsize(*a))
		{
			pa(a, b);
			ra(a);
			return ;
		}
	if (ft_lstsize(*a)/2 >= i)
	{
		while (j++ < i)
			ra(a);
		j = 0;
		pa(a, b);
		while (j++ < i)
			rra(a);
		return ;
	}
	while (j++ + ft_lstsize(*a)/2 < i)
		rra(a);
	j = 0;
	pa(a, b);
	while (j++ + ft_lstsize(*a)/2 < i)
		ra(a);
}

void	sort_five(t_list **a, t_list **b)
{
	int	to_push;
	int	i;

	to_push = ft_lstsize(*a) - 3;
	i = 0;
	while (to_push - i++ > 0)
		pb(a, b);
	if (ft_lstsize(*a) < 2)
		return ;
	if (ft_lstsize(*a) < 3)
	{
		if (((t_data *)(*b)->content)->data > \
			((t_data *)(*b)->next->content)->data)
			sa(a);
		return ;
	}
	sort_three(a);
	((t_data *)(*a)->content)->pivot = 1;
	while (--i > 0)
		insert_position(a, b);
}
