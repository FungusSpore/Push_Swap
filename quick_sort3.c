/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:04:48 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:29 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	init_partitions(t_list **a, t_list **b, int *partition_sizes)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	i = size;
	while (i--)
	{
		if (((t_data *)(*a)->content)->index >= (size/3)*2)
		{
			partition_sizes[0]++;
			ra(a);
		}
		else if (((t_data *)(*a)->content)->index <= (size/3))
		{
			partition_sizes[2]++;
			pb(a, b);
			rb(b);
		}
		else 
		{
			partition_sizes[1]++;
			pb(a, b);
		}
	}
	return (size);
}

void	big(t_list **a, t_list **b, int *partition_sizes)
{
	if (partition_sizes[0] < 2)
		return ;
	
	quick_sort3(a, b, size, partition_sizes);
}

void	quick_sort3(t_list **a, t_list **b, int size, int *partition_sizes)
{
	big(a, b, size/3 * 2, partition_sizes);
	mid(a, b, size);
	small(a, b, size/3, partition_sizes[2]);
}
