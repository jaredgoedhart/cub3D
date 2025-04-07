/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:24 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 15:20:13 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zero(void *s, size_t size)
{
	while (size--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb && size && nmemb > (UINT_MAX / size))
		return (NULL);
	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_zero(memory, nmemb * size);
	return (memory);
}

// int main(void)
// {
//     size_t nmemb = 10; //wij willen 10 elementen toewijzen voor het geheugen
//     size_t size = sizeof(int); //ze hebben een size van int of toewel 4
//     int *arr; //wat wordt gecalloced
//     arr = (int*)ft_calloc(nmemb, size);
//     if (!arr)
//         printf("Memory allocation failed\size");
//     else
//     {
//         printf("Memory successfully allocated\size");
//         free(arr);
//     }
//     return 0;
// }