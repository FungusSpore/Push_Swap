/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_upgraded.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:11:42 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/05 21:41:11 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			data->index = 0;
			ft_lstadd_back(&a, ft_lstnew(data));
		}
		free(nums);
		j = 0;
		i++;
	}
	return (a);
}

void	push_swap(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int		partition_sizes[3];

	a = NULL;
	b = NULL;
	ft_bzero(partition_sizes, 3);
	if (argc < 2)
		return ;
	if (check_errors(argc, argv))
	{
		ft_printf("Error\n");
		return ;
	}
	a = init_stack_a(argc, argv, a);
	presort_enumeration(a);
	quick_sort3(&a, &b, init_partitions(&a, &b, partition_sizes), partition_sizes);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
