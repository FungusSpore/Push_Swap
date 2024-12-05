/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:12 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/05 15:52:21 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include "libft/libft.h"

# define THRESHOLD 3

typedef struct s_data
{
	int data;
	int index;
}			t_data;
// enumeration
void	presort_enumeration(t_list *a);

// insertion sort
void	sort_five(t_list **a, t_list **b);

// quick sort 3
void	quick_sort3(t_list **a, t_list **b, int size, int *partition_sizes);
int	init_partitions(t_list **a, t_list **b, int *partition_sizes);

// operations
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif // !PUSH_SWAP_H
