/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:47:52 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 19:58:50 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (csrc < cdest)
	{
		while (n-- > 0)
			cdest[n] = csrc[n];
	}
	else
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (cdest);
}

// int main(void)
// {
// 	char src[] = "Arca - Alive";
// 	char dest[20];
// 	size_t n = 7;
// 	ft_memmove(dest, src, n);
// 	dest[n] = '\0'; //null-terminate the destination string
// 	printf("Source: %s\n", src);
// 	printf("Destination: %s\n", dest);
// 	return (0);
// }