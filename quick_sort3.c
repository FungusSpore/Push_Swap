/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:04:48 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/05 22:47:05 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

void	big(t_list **a, t_list **b, int size, int *partition_sizes)
{
	int	i;
	int	mid_count;
	int	small_count;

	i = partition_sizes[0];
	mid_count = 0;
	small_count = 0;
	if (partition_sizes[0] < 2)
		return ;
	while (i--)
	{
		if (((t_data *)(*a)->content)->index >= (size/3)*2)
			ra(a);
		else if (((t_data *)(*a)->content)->index <= (size/3))
		{
			partition_sizes[0]--;
			small_count++;
			pb(a, b);
			rb(b);
		}
		else 
		{
			partition_sizes[0]--;
			mid_count++;
			pb(a, b);
		}
	}
	quick_sort3(a, b, partition_sizes[0], partition_sizes);
	while (mid_count--)
		pa(a, b);
	while (small_count--)
	{
		rrb(b);
		pa(a, b);
	}
}

void	mid(t_list **a, t_list **b, int size, int *partition_sizes)
{
	
}

void	small(t_list **a, t_list **b, int size, int *partition_sizes)
{

}

// size to determine the cut off for the sort
// partition_sizes to keep track of how much is left in the partitions
void	quick_sort3(t_list **a, t_list **b, int size, int *partition_sizes)
{
	big(a, b, partition_sizes[0], partition_sizes);
	mid(a, b, size);
	small(a, b, size/3, partition_sizes[2]);
}
