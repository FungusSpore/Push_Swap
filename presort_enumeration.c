/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_enumeration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:55:16 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/05 00:01:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	del(void *data)
{
	free(data);
}

static void	*get_data(void *data)
{
	return (data);
}

static void	quick_sort_helper(t_list **currentj, t_list **currenti, t_list *pivot)
{
	t_list	*temp;

	if (((t_data *)pivot->content)->data < ((t_data *)(*currentj)->content)->data \
		|| *currentj == pivot)
	{
		temp = (*currenti)->content;
		(*currenti)->content = (*currentj)->content;
		(*currentj)->content = temp;
		if ((*currentj) != pivot)
			*currenti = (*currenti)->next;
	}
	*currentj = (*currentj)->next;
}

static void	quick_sort(t_list *start, t_list *end)
{
	t_list	*currenti;
	t_list	*currentj;
	t_list	*pivot;
	void		*temp;

	if (start->next == end)
		return ;
	pivot = start;
	currenti = start;
	currentj = start;
	while (pivot->next != end)
		pivot = pivot->next;
	while (currentj != end)
		quick_sort_helper(&currentj, &currenti, pivot);
	quick_sort(start, currenti);
	quick_sort(currenti->next, end);
}

void	presort_enumeration(t_list *a)
{
	t_list	*temp;
	t_list	*next;
	int		i;

	if (!a)
		return ;
	i = ft_lstsize(a);
	temp = ft_lstmap(a, get_data, del);	
	quick_sort(temp, NULL);
	while (temp)
	{
		((t_data *)temp->content)->index = i--;
		temp = temp->next;
	}
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
//
//
// // Function to create a new node
// t_list* create_node(int value) {
//     t_list *new_node = (t_list *)malloc(sizeof(t_list));
//     int *int_ptr = (int *)malloc(sizeof(int));
//     *int_ptr = value;
//     new_node->content = int_ptr;
//     new_node->next = NULL;
//     return new_node;
// }
//
// // Function to append a node to the list
// void append(t_list **head, int value) {
//     t_list *new_node = create_node(value);
//     if (*head == NULL) {
//         *head = new_node;
//         return;
//     }
//     t_list *current = *head;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     current->next = new_node;
// }
//
// // Function to print the list
// void print_list(t_list *head) {
//     t_list *current = head;
//     while (current != NULL) {
//         printf("%d ", *(int *)(current->content));
//         current = current->next;
//     }
//     printf("\n");
// }
//
// // Function to free the list
// void free_list(t_list *head) {
//     t_list *current = head;
//     while (current != NULL) {
//         t_list *temp = current;
//         current = current->next;
//         free(temp->content);
//         free(temp);
//     }
// }
//
// int main() {
//     t_list *list = NULL;
//
//     // Adding test case data
//     append(&list, 5);
//     append(&list, 3);
//     append(&list, 8);
//     append(&list, 1);
//     append(&list, 7);
//
//     printf("Unsorted list: ");
//     print_list(list);
//
//     // Sort the list
//     quick_sort(list, NULL);
//
//     printf("Sorted list: ");
//     print_list(list);
//
//     // Free the list
//     free_list(list);
//
//     return 0;
// }
