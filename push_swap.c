/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:58:35 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/04 16:19:06 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// quick sort
// first push first node into b to act as pivot and marked as such
// for b stack start from big to small 
// so for any node that is smaller than pivot pb, rb
// if bigger pb
// do until end
// if first index isn't a pivot and next also not
// pa first index into stack a set as pivot
// for stack a small to big
// if node is greater than pivot then pa, ra
// else pa
// once done pb all back into b
// check if first index or second is pivot is so rb them down until a non pivot is reaced and sort them at a again
// once all a pivot pa all back then it is sorted

// to check is sorted in both sequence
int		is_sorted(t_list *a, int reverse)
{
	int	prev;

	if (!a)
		return (-1);
	prev = ((t_data *)a->content)->data;
	while (a->next)
	{
		a = a->next;
		if (prev > ((t_data*)a->content)->data && !reverse)
			return (0);
		if (prev < ((t_data*)a->content)->data && reverse)
			return (0);
		prev = ((t_data *)a->content)->data;
	}
	return (1);
}

void	set_pivot_all(void	*data)
{
	((t_data *)data)->pivot = 1;
}

void	rotate_pivots(t_list **b, int *is_max)
{
	t_list *current;
	int		prev;

	while (((t_data *)(*b)->content)->pivot && !((t_data *)(*b)->content)->is_max)
	{
		if (!*is_max)
		{
			((t_data *)(*b)->content)->is_max = 1;
			*is_max = 1;
		}
		rb(b);
	}
	// printf("check sorted\n");
	current = *b;
	prev = ((t_data *)current->content)->data;
	// printf("Init\n");
	while (current->next)
	{
		// printf("start\n");
		current = current->next;
		if (prev < ((t_data*)current->content)->data)
			return ;
		prev = ((t_data *)current->content)->data;
		// printf("end\n");
	}
	// printf("rotate\n");
	while (!(((t_data *)(*b)->content)->pivot))
	{
		if (!*is_max)
		{
			((t_data *)(*b)->content)->is_max = 1;
			*is_max = 1;
		}
		rb(b);
	}
}

int	get_partition_size(t_list *b)
{
	int	size;
	
	size = 0;
	while (b && !(((t_data *)b->content)->pivot))
	{
		b = b->next;
		size++;
	}
	return (size);
}

void	quick_sort(t_list **a, t_list **b)
{
	int	pivot;

	pivot = ((t_data *)(*b)->content)->data;
	((t_data *)(*b)->content)->pivot = 1;
	pa(a, b);
	// push to stack a until a pivot is reached
	while (!((t_data *)(*b)->content)->pivot)
	{
		pa(a, b);
		if (((t_data *)(*a)->content)->data > pivot)
			ra(a);
	}
}

void	reverse_quick_sort(t_list **a, t_list **b)
{
	int	pivot;
	int	i;

	i = 0;
	if (((t_data *)(*a)->content)->pivot)
		pb(a, b);
	if (!*a)
		return ;
	pivot = ((t_data *)(*a)->content)->data;
	((t_data *)(*a)->content)->pivot = 1;
	pb(a, b);
	if (!*a)
		return ;
	// push to stack a until a pivot is reached
	while (*a && (!((t_data *)(*a)->content)->pivot))
	{
		pb(a, b);
		if (((t_data *)(*b)->content)->data < pivot)
			sb(b);
		else
		{
			rb(b);
			i++;
		}
	}
	while (i--)
		rrb(b);
}

void	sort(t_list **a, t_list **b, int *is_max)
{
	int	pivot;
	int	size;

	if (is_sorted(*b, 1))
		return ;
	// ft_printf("entered rotate_pivots\n");
	rotate_pivots(b, is_max);
	if (is_sorted(*b, 1))
		return ;
	size = get_partition_size(*b);
	// if (size < THRESHOLD + 1)
	// {
	// 	// printf("entered sort_five\n");
	// 	while (size--)
	// 		pa(a, b);
	// 	sort_five(a, b);
	// 	// printf("exited sort_five\n");
	// 	ft_lstiter(*a, set_pivot_all);
	// 	while (*a)
	// 		pb(a, b);
	// }
	// else
	// {
	quick_sort(a, b);
	while (*a)
		reverse_quick_sort(a, b);
	// }
	sort(a ,b, is_max);
}

int	ft_atol(const char *nptr)
{
	long	result;
	int		is_nega;

	is_nega = 0;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_nega = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr) - '0';
		nptr++;
	}
	if (is_nega)
		result *= -1;
	return (result);
}

int	check_errors(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while(*str)
		{
			if (!(ft_isdigit(*str) || *str == ' '))
				return (1);
			str++;
		}
		j = i + 1;
		while (j < argc)
			if (ft_strncmp(argv[i], argv[j++], -1) == 0)
				return (1);
		if (INT_MAX < atol(argv[i]) || atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

t_list	*init_stack_a(int argc, char **argv, t_list *a)
{
	t_data	*data;
	char		**nums;
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		while (nums[j])
		{
			data = malloc(sizeof(t_data));
			if (!data)
				return (NULL);
			data->data = ft_atoi(nums[j++]);
			data->pivot = 0;
			data->is_max = 0;
			ft_lstadd_back(&a, ft_lstnew(data));
		}
		free(nums);
		j = 0;
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int	pivot;
	int	is_max;

	a = NULL;
	b = NULL;
	is_max = 0;
	if (argc < 2)
		return (1);
	if (check_errors(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	a = init_stack_a(argc, argv, a);
	// if (ft_lstsize(a) > THRESHOLD)
	// {
	pb(&a, &b);
	((t_data *)b->content)->pivot = 1;
	pivot = ((t_data *)b->content)->data;
	while (a)
	{
		pb(&a, &b);
		if (((t_data *)b->content)->data < pivot)
			rb(&b);
	}
	sort(&a, &b, &is_max);
	// }
	// else 
	// 	sort_five(&a, &b);
	while (b)
		pa(&a, &b);
	return (0);
}
