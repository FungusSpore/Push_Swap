/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:19:22 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/02 17:47:32 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/// copies a memory address into another does not account for overlap
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char *dest = malloc(11);
// 	char src[] = "Hello World";
// 	char src2[] = "Hello World";
//
// 	memcpy(src + 2, src, 5);
// 	ft_memcpy(src2 + 2, src2, 5);	
// 	printf("%s\n", src);
// 	printf("%s\n", src2);
// 	return (0);
// }
