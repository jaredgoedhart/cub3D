/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:05:23 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 20:01:34 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n > 0)
	{
		while (src[i] != '\0' && i < n - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[j] != '\0')
		j++;
	return (j);
}

// int main(void)
// {
// 	char	source[] = "A Moon Shaped Pool";
// 	char	destination[42];
// 	ft_strlcpy(destination, source, 5);
// 	destination[5] = '\0'; //null-terminate the destination string
// 	printf("Source: %s\n", source);
// 	printf("Destination: %s\n", destination);
// 	return (0);
// }