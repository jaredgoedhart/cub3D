/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoedhar <jgoedhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:05:23 by jgoedhar          #+#    #+#             */
/*   Updated: 2023/11/05 21:46:28 by jgoedhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

// int main() {
//    char dst[10] = "Alfa";
//    const char src[] = " Mist";
//    size_t size = 0;

//    while (dst[size] != '\0')
//        size++;

//    ft_strlcat(dst, src, size + 1);

//    printf("%s\n", dst);
//    return 0;
// }