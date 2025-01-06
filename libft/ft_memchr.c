/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:07:27 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 15:08:00 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)(unsigned char *)s - 1);
	}
	return (NULL);
}

// int main(void)
// {
//     const char *s = "Fz Pseudotimestretch+E+3 [138.85]";
//     int c = '8';
//     size_t n = 30;
//     void *result = ft_memchr(s, c, n);
//     if (result != NULL) {
//         printf("found%ld\n", (unsigned char *)result - (unsigned char *)s);
//     } else {
//         printf("Char not found in the first %zu bytes\n", n);
//     }
//     return 0;
// }